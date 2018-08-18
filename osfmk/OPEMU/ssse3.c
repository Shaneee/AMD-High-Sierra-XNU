/*
             .d8888b.   .d8888b.   .d8888b.  8888888888 .d8888b.  
            d88P  Y88b d88P  Y88b d88P  Y88b 888       d88P  Y88b 
            Y88b.      Y88b.      Y88b.      888            .d88P 
             "Y888b.    "Y888b.    "Y888b.   8888888       8888"  
                "Y88b.     "Y88b.     "Y88b. 888            "Y8b. 
                  "888       "888       "888 888       888    888 
            Y88b  d88P Y88b  d88P Y88b  d88P 888       Y88b  d88P 
             "Y8888P"   "Y8888P"   "Y8888P"  8888888888 "Y8888P"  
*/

#include "opemu.h"
#include "ssse3_priv.h"

/**
 * Load operands from memory/register, store in obj.
 * @return: 0 if success
 */
int ssse3_grab_operands(ssse3_t *ssse3_obj)
{
	if (ssse3_obj->islegacy) {
		_store_mmx (ssse3_obj->udo_dst->base - UD_R_MM0, &ssse3_obj->dst.uint64[0]);
		if (ssse3_obj->udo_src->type == UD_OP_REG) {
			_store_mmx (ssse3_obj->udo_src->base - UD_R_MM0, &ssse3_obj->src.uint64[0]);
		} else {
			// m64 load
			int64_t disp = 0;
			uint8_t disp_size = ssse3_obj->udo_src->offset;
			uint64_t address;
			
			if (ssse3_obj->udo_src->scale) goto bad; // TODO

			if (retrieve_reg (ssse3_obj->op_obj->state,
				ssse3_obj->udo_src->base, &address) != 0) goto bad;

			switch (disp_size) {
			case 8: disp = ssse3_obj->udo_src->lval.sbyte; break;
			case 16: disp = ssse3_obj->udo_src->lval.sword; break;
			case 32: disp = ssse3_obj->udo_src->lval.sdword; break;
			case 64: disp = ssse3_obj->udo_src->lval.sqword; break;
			}

			address += disp;

			if (ssse3_obj->op_obj->ring0)
				ssse3_obj->src.uint64[0] = * ((uint64_t*) (address));
			else copyin (address, (char*) &ssse3_obj->src.uint64[0], 8);
		}
	} else {
		_store_xmm (ssse3_obj->udo_dst->base - UD_R_XMM0, &ssse3_obj->dst.uint128);
		if (ssse3_obj->udo_src->type == UD_OP_REG) {
			_store_xmm (ssse3_obj->udo_src->base - UD_R_XMM0, &ssse3_obj->src.uint128);
		} else {
			// m128 load
			int64_t disp = 0;
			uint8_t disp_size = ssse3_obj->udo_src->offset;
			uint64_t address;
			
			if (ssse3_obj->udo_src->scale) goto bad; // TODO

			if (retrieve_reg (ssse3_obj->op_obj->state,
				ssse3_obj->udo_src->base, &address) != 0) goto bad;

			switch (disp_size) {
			case 8: disp = ssse3_obj->udo_src->lval.sbyte; break;
			case 16: disp = ssse3_obj->udo_src->lval.sword; break;
			case 32: disp = ssse3_obj->udo_src->lval.sdword; break;
			case 64: disp = ssse3_obj->udo_src->lval.sqword; break;
			}

			address += disp;

			if (ssse3_obj->op_obj->ring0)
				ssse3_obj->src.uint128 = * ((__uint128_t*) (address));
			else copyin (address, (char*) &ssse3_obj->src.uint128, 16);
		}
	}

    return 0;

    // Only reached if bad
bad:	return -1;
}

/**
 * Store operands from obj to memory/register.
 * @return: 0 if success
 */
int ssse3_commit_results(const ssse3_t *ssse3_obj)
{
	if (ssse3_obj->islegacy) {
		_load_mmx (ssse3_obj->udo_dst->base - UD_R_MM0, (void*) &ssse3_obj->res.uint64[0]);
	} else {
		_load_xmm (ssse3_obj->udo_dst->base - UD_R_XMM0, (void*) &ssse3_obj->res.uint128);
	}

    return 0;

    // Only reached if bad
//bad:	return -1;
}


/**
 * Main function for the ssse3 portion. Check if the offending
 * opcode is part of the ssse3 instruction set, if not, quit early.
 * if so, then we build the appropriate context, and jump to the right function.
 * @param op_obj: opemu object
 * @return: zero if an instruction was emulated properly
 */
int op_sse3x_run(const op_t *op_obj)
{
	ssse3_t ssse3_obj;
	ssse3_obj.op_obj = op_obj;
	const uint32_t mnemonic = ud_insn_mnemonic(ssse3_obj.op_obj->ud_obj);
	ssse3_func opf;

	switch (mnemonic) {
    case UD_Ipcmpestri:	opf = pcmpestri; goto sse42_common;
	case UD_Ipcmpestrm:	opf = pcmpestrm; goto sse42_common;
	case UD_Ipcmpistri:	opf = pcmpistri; goto sse42_common;
    case UD_Ipcmpistrm: opf = pcmpistrm; goto sse42_common;
    case UD_Ipcmpgtq:	opf = pcmpgtq;   goto sse42_common;
sse42_common:
	

	goto ssse3_common;


	case UD_Ipsignb:	opf = psignb;	goto ssse3_common;
	case UD_Ipsignw:	opf = psignw;	goto ssse3_common;
	case UD_Ipsignd:	opf = psignd;	goto ssse3_common;

	case UD_Ipabsb:		opf = pabsb;	goto ssse3_common;
	case UD_Ipabsw:		opf = pabsw;	goto ssse3_common;
	case UD_Ipabsd:		opf = pabsd;	goto ssse3_common;

	case UD_Ipalignr:	opf = palignr;	goto ssse3_common;

	case UD_Ipshufb:	opf = pshufb;	goto ssse3_common;

	case UD_Ipmulhrsw:	opf = pmulhrsw;	goto ssse3_common;

	case UD_Ipmaddubsw:	opf = pmaddubsw;	goto ssse3_common;

	case UD_Iphsubw:	opf = phsubw;	goto ssse3_common;
	case UD_Iphsubd:	opf = phsubd;	goto ssse3_common;

	case UD_Iphsubsw:	opf = phsubsw;	goto ssse3_common;

	case UD_Iphaddw:	opf = phaddw;	goto ssse3_common;
	case UD_Iphaddd:	opf = phaddd;	goto ssse3_common;

	case UD_Iphaddsw:	opf = phaddsw;	goto ssse3_common;
ssse3_common:
	
	ssse3_obj.udo_src = ud_insn_opr (op_obj->ud_obj, 1);
	ssse3_obj.udo_dst = ud_insn_opr (op_obj->ud_obj, 0);
	ssse3_obj.udo_imm = ud_insn_opr (op_obj->ud_obj, 2);

	// run some sanity checks,
	if (ssse3_obj.udo_dst->type != UD_OP_REG) goto bad;
	if ((ssse3_obj.udo_src->type != UD_OP_REG)
		&& (ssse3_obj.udo_src->type != UD_OP_MEM))
		goto bad;

	// i'd like to know if this instruction is legacy mmx
	if ((ssse3_obj.udo_dst->base >= UD_R_MM0)
		&& (ssse3_obj.udo_dst->base <= UD_R_MM7)) {
		ssse3_obj.islegacy = 1;
	} else ssse3_obj.islegacy = 0;
	
	if (ssse3_grab_operands(&ssse3_obj) != 0) goto bad;

	opf(&ssse3_obj);

	if (ssse3_commit_results(&ssse3_obj)) goto bad;

	goto good;

	default: goto bad;
	}

good:
	return 0;

    // Only reached if bad
bad:
	return -1;
}

#define SATSW(x) ((x > 32767)? 32767 : ((x < -32768)? -32768 : x) )

/**
 * Negate/zero/preserve
 */
void psignb (ssse3_t *this)
{
	const int8_t *src = &this->src.int8[0];
	const int8_t *dst = &this->dst.int8[0];
	int8_t *res = &this->res.int8[0];

	int count = (this->islegacy) ? 8 : 16;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *dst;
		else if (*src == 0) *res = 0;
		else if (*src > 0) *res = *dst;

		++res; ++src; ++dst;
	}
}

/**
 * Negate/zero/preserve
 */
void psignw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 4 : 8;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *dst;
		else if (*src == 0) *res = 0;
		else if (*src > 0) *res = *dst;

		++res; ++src; ++dst;
	}
}

/**
 * Negate/zero/preserve
 */
void psignd (ssse3_t *this)
{
	const int32_t *src = &this->src.int32[0];
	const int32_t *dst = &this->dst.int32[0];
	int32_t *res = &this->res.int32[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *dst;
		else if (*src == 0) *res = 0;
		else if (*src > 0) *res = *dst;

		++res; ++src; ++dst;
	}
}

/**
 * Absolute value
 */
void pabsb (ssse3_t *this)
{
	const int8_t *src = &this->src.int8[0];
	const int8_t *dst = &this->dst.int8[0];
	int8_t *res = &this->res.int8[0];

	int count = (this->islegacy) ? 8 : 16;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *src;
		else *res = *src;

		++res; ++src; ++dst;
	}
}

/**
 * Absolute value
 */
void pabsw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 4 : 8;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *src;
		else *res = *src;

		++res; ++src; ++dst;
	}
}

/**
 * Absolute value
 */
void pabsd (ssse3_t *this)
{
	const int32_t *src = &this->src.int32[0];
	const int32_t *dst = &this->dst.int32[0];
	int32_t *res = &this->res.int32[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		if (*src < 0) *res = - *src;
		else *res = *src;

		++res; ++src; ++dst;
	}
}

/**
 * Concatenate and shift
 */ 
void palignr (ssse3_t *this)
{
	uint8_t imm = this->udo_imm->lval.ubyte;

	if (this->islegacy) {
		__uint128_t temp1 = this->dst.uint64[0];
		temp1 <<= 64;
		temp1 |= this->src.uint64[0];
		temp1 >>= (imm * 8);
		this->res.uint128 = temp1;
	} else {
        // AnV - Cast fixed
		__uint128_t temp1[2];
		uint8_t *shiftp; // that type matters for pointer arithmetic
        uint64_t shiftpaddr;
		temp1[0] = this->src.uint128;
		temp1[1] = this->dst.uint128;
		shiftp = (uint8_t*) &temp1[0];
		shiftp += imm;
        shiftpaddr = (uint64_t)shiftp;
		this->res.uint128 = * ((__uint128_t*) shiftpaddr);
	}
}

/**
 * Shuffle Bytes
 */
void pshufb (ssse3_t *this)
{
	const uint8_t *src = &this->src.uint8[0];
	uint8_t *res = &this->res.uint8[0];

	int count = (this->islegacy) ? 8 : 16;
	uint8_t mask = (this->islegacy) ? 0b0111 : 0b1111;
	for (int i = 0; i < count; ++ i) {
		if (*src & 0x80) *res = 0;
		else *res = this->dst.uint8[ *src & mask ];

		++res; ++src;
	}
}

/**
 * Multiply high with round and scale
 */
void pmulhrsw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 4 : 8;
	for (int i = 0; i < count; ++i) {
		int32_t temp1 = (*dst) * (*src);
		temp1 >>= 14;
		temp1++;
		temp1 >>= 1;
		*res = temp1 & 0xFFFF;

		++res; ++src; ++dst;
	}
}

/**
 * Multiply and add
 */
void pmaddubsw (ssse3_t *this)
{
	const int8_t *src = &this->src.int8[0];
	const uint8_t *dst = &this->dst.uint8[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 4 : 8;
	for (int i = 0; i < count; ++i) {
		int64_t temp1 = (src[0] * dst[0]) + (src[1] * dst[1]);
		*res = SATSW(temp1);

		++res;
		src += 2;
		dst += 2;
	}	
}

/**
 * Horizontal subtract
 */
void phsubw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		*res = (dst[0]) - (dst[1]);

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = (src[0]) - (src[1]);

		++res;
		src += 2;
	}
}

/**
 * Horizontal subtract
 */
void phsubd (ssse3_t *this)
{
	const int32_t *src = &this->src.int32[0];
	const int32_t *dst = &this->dst.int32[0];
	int32_t *res = &this->res.int32[0];

	int count = (this->islegacy) ? 1 : 2;
	for (int i = 0; i < count; ++ i) {
		*res = (dst[0]) - (dst[1]);

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = (src[0]) - (src[1]);

		++res;
		src += 2;
	}
}

/**
 * Horizontal subtract and saturate
 */
void phsubsw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		*res = SATSW((dst[0]) - (dst[1]));

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = SATSW((src[0]) - (src[1]));

		++res;
		src += 2;
	}
}

/**
 * Horizontal add
 */
void phaddw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		*res = dst[0] + dst[1];

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = src[0] + src[1];

		++res;
		src += 2;
	}
}

/**
 * Horizontal add
 */
void phaddd (ssse3_t *this)
{
	const int32_t *src = &this->src.int32[0];
	const int32_t *dst = &this->dst.int32[0];
	int32_t *res = &this->res.int32[0];

	int count = (this->islegacy) ? 1 : 2;
	for (int i = 0; i < count; ++ i) {
		*res = dst[0] + dst[1];

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = src[0] + src[1];

		++res;
		src += 2;
	}
}

/**
 * Horizontal add and saturate
 */
void phaddsw (ssse3_t *this)
{
	const int16_t *src = &this->src.int16[0];
	const int16_t *dst = &this->dst.int16[0];
	int16_t *res = &this->res.int16[0];

	int count = (this->islegacy) ? 2 : 4;
	for (int i = 0; i < count; ++ i) {
		*res = SATSW(dst[0] + dst[1]);

		++res;
		dst += 2;
	}
	for (int i = 0; i < count; ++ i) {
		*res = SATSW(src[0] + src[1]);

		++res;
		src += 2;
	}
}

