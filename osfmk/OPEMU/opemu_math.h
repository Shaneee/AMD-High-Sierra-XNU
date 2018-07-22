/* Needed unions */
typedef union
{
        float value;
        uint32_t word;
    } ieee_float_shape_type;

typedef union
{
        double value;
        struct
        {
                uint32_t lsw;
                uint32_t msw;
            } parts;
    } ieee_double_shape_type;

typedef union
{
        long double value;
        struct
        {
                uint64_t lsw;
                uint64_t msw;
            } parts;
    } ieee_long_double_shape_type;

/* 32-bit (float) */
#define GET_FLOAT_WORD(i,d) \
  do { \
        ieee_float_shape_type gf_u; \
        gf_u.value = (d); \
        (i) = gf_u.word; \
      } while (0)

#define SET_FLOAT_WORD(d,i) \
  do { \
        ieee_float_shape_type sf_u; \
        sf_u.word = (i); \
        (d) = sf_u.value; \
      } while (0)

/* 64-bit (double) */
#define EXTRACT_WORDS(ix0,ix1,d) \
  do { \
        ieee_double_shape_type ew_u; \
        ew_u.value = (d); \
        (ix0) = ew_u.parts.msw; \
        (ix1) = ew_u.parts.lsw; \
      } while (0)

#define INSERT_WORDS(d,ix0,ix1) \
  do { \
        ieee_double_shape_type iw_u; \
        iw_u.parts.msw = (ix0); \
        iw_u.parts.lsw = (ix1); \
        (d) = iw_u.value; \
      } while (0)

/* 128-bit (long double) */
#define GET_LDOUBLE_WORDS(ix0,ix1,d) \
  do { \
        ieee_long_double_shape_type qw_u; \
        qw_u.value = (d); \
        (ix0) = qw_u.parts.msw; \
        (ix1) = qw_u.parts.lsw; \
      } while (0)

#define SET_LDOUBLE_WORDS(d,ix0,ix1) \
  do { \
        ieee_long_double_shape_type qw_u; \
        qw_u.parts.msw = (ix0); \
        qw_u.parts.lsw = (ix1); \
        (d) = qw_u.value; \
      } while (0)

float opemu_truncf(float x);
double opemu_trunc(double x);
long double opemu_truncl(long double x);