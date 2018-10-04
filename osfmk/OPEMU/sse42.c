#include "ssse3_priv.h"

#define CFLAG 0x00000001
#define ZFLAG 0x00000002
#define SFLAG 0x00000004
#define OFLAG 0x00000008
#define AFLAG 0x00000010
#define PFLAG 0x00000020

#define PCMPSTR_EQ(X, Y, RES) \
{							\
    int __size = (sizeof (*X) ^ 3) * 8;			\
    int __i, __j;					\
    for (__i = 0; __i < __size; __i++)			\
        for (__j = 0; __j < __size; __j++)		\
            RES[__j][__i] = (X[__i] == Y[__j]);		\
}

#define PCMPSTR_RNG(X, Y, RES) \
{							\
    int __size = (sizeof (*X) ^ 3) * 8;			\
    int __i, __j;					\
    for (__j = 0; __j < __size; __j++)			\
        for (__i = 0; __i < __size - 1; __i += 2)		\
        {						\
            RES[__j][__i] = (Y[__j] >= X[__i]);		\
            RES[__j][__i+1] = (Y[__j] <= X[__i + 1]);	\
        }						\
}

static int
calc_str_len (__int128_t val, const int mode)
{
    union
    {
        __int128_t x;
        char c[16];
        short s[8];
    } s;
    int i;
    int dim  = (mode & 1) == 0 ? 16 : 8;
    
    s.x = val;
    
    if ((mode & 1))
    {
        for (i = 0; i < dim; i++)
            if (s.s[i] == 0)
                break;
    }
    else
    {
        for (i = 0; i < dim; i++)
            if (s.c[i] == 0)
                break;
    }
    
    return i;
}

static void
override_invalid (unsigned char res[16][16], int la, int lb,
                  const int mode, int dim)
{
    int i, j;
    
    for (j = 0; j < dim; j++)
        for (i = 0; i < dim; i++)
            if (i < la && j >= lb)
                res[j][i] = 0;
            else if (i >= la)
                switch ((mode & 0x0C))
            {
                case 0x00:
                case 0x04:
                    res[j][i] = 0;
                    break;
                case 0x08:
                    res[j][i] = (j >= lb) ? 1: 0;
                    break;
                case 0x0C:
                    res[j][i] = 1;
                    break;
            }
}

static void
calc_matrix (__int128_t a, int la, __int128_t b, int lb, const int mode,
             unsigned char res[16][16])
{
    union
    {
        __int128_t x;
        signed char sc[16];
        unsigned char uc[16];
        signed short ss[8];
        unsigned short us[8];
    } d, s;
    
    d.x = a;
    s.x = b;
    
    switch ((mode & 3))
    {
        case 0x00:
            if ((mode & 0x0C) == 0x04)
            {
                PCMPSTR_RNG (d.uc, s.uc, res);
            }
            else
            {
                PCMPSTR_EQ (d.uc, s.uc, res);
            }
            break;
        case 0x01:
            if ((mode & 0x0C) == 0x04)
            {
                PCMPSTR_RNG (d.us, s.us, res);
            }
            else
            {
                PCMPSTR_EQ (d.us, s.us, res);
            }
            break;
        case 0x02:
            if ((mode & 0x0C) == 0x04)
            {
                PCMPSTR_RNG (d.sc, s.sc, res);
            }
            else
            {
                PCMPSTR_EQ (d.sc, s.sc, res);
            }
            break;
        case 0x03:
            if ((mode & 0x0C) == 0x04)
            {
                PCMPSTR_RNG (d.ss, s.ss, res);
            }
            else
            {
                PCMPSTR_EQ (d.ss, s.ss, res);
            }
            break;
    }
    
    override_invalid (res, la, lb, mode, (mode & 1) == 0 ? 16 : 8);
}

static int
pcmpstr_calc_res (__int128_t a, int la, __int128_t b, int lb, const int mode)
{
    unsigned char mtx[16][16];
    int i, j, k, dim, res = 0;
    
    memset (mtx, 0, sizeof (mtx));
    
    dim = (mode & 1) == 0 ? 16 : 8;
    
    if (la < 0)
        la = -la;
    
    if (lb < 0)
        lb = -lb;
    
    if (la > dim)
        la = dim;
    
    if (lb > dim)
        lb = dim;
    
    calc_matrix (a, la, b, lb, mode, mtx);
    
    switch ((mode & 0x0C))
    {
        case 0:
            for (i = 0; i < dim; i++)
                for (j = 0; j < dim; j++)
                    if (mtx[i][j])
                        res |= (1 << i);
            break;
            
        case 4:
            for (i = 0; i < dim; i += 2)
                for(j = 0; j < dim; j++)
                    if (mtx[j][i] && mtx[j][i+1])
                        res |= (1 << j);
            break;
            
        case 8:
            for(i = 0; i < dim; i++)
                if (mtx[i][i])
                    res |= (1 << i);
            break;
            
        case 12:
            for(i = 0; i < dim; i++)
            {
                unsigned char val = 1;
                
                for (j = 0, k = i; j < dim - i && k < dim; j++, k++)
                    val &= mtx[k][j];
                
                if (val)
                    res |= (1 << i);
                else
                    res &= ~(1 << i);
            }
            break;
    }
    
    switch ((mode & 0x30))
    {
        case 0x00:
        case 0x20:
            break;
            
        case 0x10:
            res ^= -1;
            break;
            
        case 0x30:
            for (i = 0; i < lb; i++)
                if (res & (1 << i))
                    res &= ~(1 << i);
                else
                    res |= (1 << i);
            break;
    }
    
    return res & ((dim == 8) ? 0xFF : 0xFFFF);
}

static int
cmp_indexed (__int128_t a, int la, __int128_t b, int lb,
             const int mode, int *res2)
{
    int i, ndx;
    int dim = (mode & 1) == 0 ? 16 : 8;
    int r2;
    
    r2 = pcmpstr_calc_res (a, la, b, lb, mode);
    
    ndx = dim;
    if ((mode & 0x40))
    {
        for (i = dim - 1; i >= 0; i--)
            if (r2 & (1 << i))
            {
                ndx = i;
                break;
            }
    }
    else
    {
        for (i = 0; i < dim; i++)
            if ((r2 & (1 << i)))
            {
                ndx = i;
                break;
            }
    }
    
    *res2 = r2;
    return ndx;
}

static int
cmp_flags (__int128_t a, int la, __int128_t b, int lb,
           int mode, int res2, int is_implicit)
{
    int i;
    int flags = 0;
    int is_bytes_mode = (mode & 1) == 0;
    union
    {
        __int128_t x;
        unsigned char uc[16];
        unsigned short us[8];
    } d, s;
    
    d.x = a;
    s.x = b;
    
    /* CF: reset if (RES2 == 0), set otherwise.  */
    if (res2 != 0)
        flags |= CFLAG;
    
    if (is_implicit)
    {
        /* ZF: set if any byte/word of src xmm operand is null, reset
         otherwise.
         SF: set if any byte/word of dst xmm operand is null, reset
         otherwise.  */
        
        if (is_bytes_mode)
        {
            for (i = 0; i < 16; i++)
            {
                if (s.uc[i] == 0)
                    flags |= ZFLAG;
                if (d.uc[i] == 0)
                    flags |= SFLAG;
            }
        }
        else
        {
            for (i = 0; i < 8; i++)
            {
                if (s.us[i] == 0)
                    flags |= ZFLAG;
                if (d.us[i] == 0)
                    flags |= SFLAG;
            }
        }
    }
    else
    {
        /* ZF: set if abs value of EDX/RDX < 16 (8), reset otherwise.
         SF: set if abs value of EAX/RAX < 16 (8), reset otherwise.  */
        int max_ind = is_bytes_mode ? 16 : 8;
        
        if (la < 0)
            la = -la;
        if (lb < 0)
            lb = -lb;
        
        if (lb < max_ind)
            flags |= ZFLAG;
        if (la < max_ind)
            flags |= SFLAG;
    }
    
    /* OF: equal to RES2[0].  */
    if ((res2 & 0x1))
        flags |= OFLAG;
    
    /* AF: Reset.
     PF: Reset.  */
    return flags;
}

static inline int
cmp_ei (__int128_t *a, int la, __int128_t *b, int lb,
        const int mode, int *flags)
{
    int res2;
    int index = cmp_indexed (*a, la, *b, lb, mode, &res2);
    
    if (flags != NULL)
        *flags = cmp_flags (*a, la, *b, lb, mode, res2, 0);
    
    return index;
}

static inline int
cmp_ii (__int128_t *a, __int128_t *b, const int mode, int *flags)
{
    int la, lb;
    int res2;
    int index;
    
    la = calc_str_len (*a, mode);
    lb = calc_str_len (*b, mode);
    
    index = cmp_indexed (*a, la, *b, lb, mode, &res2);
    
    if (flags != NULL)
        *flags = cmp_flags (*a, la, *b, lb, mode, res2, 1);
    
    return index;
}

static __int128_t
cmp_masked (__int128_t a, int la, __int128_t b, int lb,
            const int mode, int *res2)
{
    union
    {
        __int128_t x;
        char c[16];
        short s[8];
    } ret;
    int i;
    int dim = (mode & 1) == 0 ? 16 : 8;
    union
    {
        int i;
        char c[4];
        short s[2];
    } r2;
    
    r2.i = pcmpstr_calc_res (a, la, b, lb, mode);
    
    ret.x = 0;
    
    if (mode & 0x40)
    {
        for (i = 0; i < dim; i++)
            if (dim == 8)
                ret.s [i] = (r2.i & (1 << i)) ? -1 : 0;
            else
                ret.c [i] = (r2.i & (1 << i)) ? -1 : 0;
    }
    else
    {
        if (dim == 16)
            ret.s[0] = r2.s[0];
        else
            ret.c[0] = r2.c[0];
    }
    
    *res2 = r2.i;
    
    return ret.x;
}

static inline __int128_t
cmp_em (__int128_t *a, int la, __int128_t *b, int lb,
        const int mode, int *flags )
{
    int res2;
    __int128_t mask = cmp_masked (*a, la, *b, lb, mode, &res2);
    
    if (flags != NULL)
        *flags = cmp_flags (*a, la, *b, lb, mode, res2, 0);
    
    return mask;
}

static inline __int128_t
cmp_im (__int128_t *a, __int128_t *b, const int mode, int *flags)
{
    int la, lb;
    int res2;
    __int128_t mask;
    
    la = calc_str_len (*a, mode);
    lb = calc_str_len (*b, mode);
    
    mask = cmp_masked (*a, la, *b, lb, mode, &res2);
    if (flags != NULL)
        *flags = cmp_flags (*a, la, *b, lb, mode, res2, 1);
    
    return mask;
}

/**
 * Compare and index string
 */
void pcmpistri	(ssse3_t *this)
{
	const int imm = this->udo_imm->lval.ubyte;
	//const int issigned = imm & 0b10;
    uint8_t islongmode = is_saved_state64(this->op_obj->state);

	__int128_t *src = &(this->src.int128);
	__int128_t *dst = &(this->dst.int128);

	int res1 = 0, res2 = 0;

	/* thanks for excusing me the nesting */

    res1 = cmp_ii(src, dst, imm, &res2);

#if 0
	printf("src: ");
	print128(this->src);
	printf("\n");

	printf("dst: ");
	print128(this->dst);
	printf("\n");

	printf("res: ");
	print128(this->res);
	printf("\n");

	printf("and the int2 is %02x\n", res2);
	printf("and the index  is %d\n", res1);
#endif

    if (islongmode)
    {
        this->op_obj->state64->rcx = res1;

        this->op_obj->state64->isf.rflags &= ~ 0b100011010101;
        this->op_obj->state64->isf.rflags |= res2;
    } else {
        this->op_obj->state32->ecx = res1;

        this->op_obj->state32->efl &= ~ 0b100011010101;
        this->op_obj->state32->efl |= res2; // C
    }
}

void pcmpestri	(ssse3_t *this)
{
	const int imm = this->udo_imm->lval.ubyte;
	//const int issigned = imm & 0b10;
    uint8_t islongmode = is_saved_state64(this->op_obj->state);
    
	__int128_t *src = &(this->src.int128);
	__int128_t *dst = &(this->dst.int128);
    
	int res1 = 0, res2 = 0;
    
	/* thanks for excusing me the nesting */
    // FIXME: How to get la + lb parameters?
    res1 = cmp_ei(src, sizeof(*src), dst, sizeof(*dst), imm, &res2);
    
#if 0
	printf("src: ");
	print128(this->src);
	printf("\n");
    
	printf("dst: ");
	print128(this->dst);
	printf("\n");
    
	printf("res: ");
	print128(this->res);
	printf("\n");
    
	printf("and the int2 is %02x\n", res2);
	printf("and the index  is %d\n", res1);
#endif
    
    if (islongmode)
    {
        this->op_obj->state64->rcx = res1;
        
        this->op_obj->state64->isf.rflags &= ~ 0b100011010101;
        this->op_obj->state64->isf.rflags |= res2;
    } else {
        this->op_obj->state32->ecx = res1;
        
        this->op_obj->state32->efl &= ~ 0b100011010101;
        this->op_obj->state32->efl |= res2; // C
    }
}

void pcmpestrm	(ssse3_t *this)
{
	const int imm = this->udo_imm->lval.ubyte;
	//const int issigned = imm & 0b10;
    uint8_t islongmode = is_saved_state64(this->op_obj->state);
    
	__int128_t *src = &(this->src.int128);
	__int128_t *dst = &(this->dst.int128);
    __int128_t *res = &(this->res.int128);
    
	int res2 = 0;
    
	/* thanks for excusing me the nesting */
    // FIXME: How to get la + lb parameters?
    *res = cmp_em(src, sizeof(*src), dst, sizeof(*dst), imm, &res2);
    
#if 0
	printf("src: ");
	print128(this->src);
	printf("\n");
    
	printf("dst: ");
	print128(this->dst);
	printf("\n");
    
	printf("res: ");
	print128(this->res);
	printf("\n");
    
	printf("and the int2 is %02x\n", res2);
	printf("and the index  is %d\n", res1);
#endif
    
    if (islongmode)
    {
        this->op_obj->state64->isf.rflags &= ~ 0b100011010101;
        this->op_obj->state64->isf.rflags |= res2;
    } else {
        this->op_obj->state32->efl &= ~ 0b100011010101;
        this->op_obj->state32->efl |= res2; // C
    }
}

void pcmpistrm	(ssse3_t *this)
{
	const int imm = this->udo_imm->lval.ubyte;
	//const int issigned = imm & 0b10;
    uint8_t islongmode = is_saved_state64(this->op_obj->state);
    
	__int128_t *src = &(this->src.int128);
	__int128_t *dst = &(this->dst.int128);
    __int128_t *res = &(this->res.int128);
    
	int res2 = 0;
    
	/* thanks for excusing me the nesting */
    
    *res = cmp_im(src, dst, imm, &res2);
    
#if 0
	printf("src: ");
	print128(this->src);
	printf("\n");
    
	printf("dst: ");
	print128(this->dst);
	printf("\n");
    
	printf("res: ");
	print128(this->res);
	printf("\n");
    
	printf("and the int2 is %02x\n", res2);
	printf("and the index  is %d\n", res1);
#endif
    
    if (islongmode)
    {
        this->op_obj->state64->isf.rflags &= ~ 0b100011010101;
        this->op_obj->state64->isf.rflags |= res2;
    } else {
        this->op_obj->state32->efl &= ~ 0b100011010101;
        this->op_obj->state32->efl |= res2; // C
    }
}

void pcmpgtq	(ssse3_t *this)
{
    this->res.int64[0] = this->src.int64[0] > this->dst.int64[0] ? 0xFFFFFFFFFFFFFFFFLL : 0;
    this->res.int64[1] = this->src.int64[1] > this->dst.int64[1] ? 0xFFFFFFFFFFFFFFFFLL : 0;
}
