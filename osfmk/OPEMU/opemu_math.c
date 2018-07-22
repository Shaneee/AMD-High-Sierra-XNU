#include <stdint.h>
#include "opemu_math.h"

/* 32-bit */
float opemu_truncf(float x)
{
        float ret = x;
        int32_t signbit=0;
        int32_t w=0;
        int32_t exponent_less_127=0;
    
        GET_FLOAT_WORD(w,ret);
    
        /* Extract sign bit. */
        signbit = w & 0x80000000;
    
        /* Extract exponent field. */
        exponent_less_127 = ((w & 0x7f800000) >> 23) - 127;
    
        if (exponent_less_127 < 23)
            {
                    if (exponent_less_127 < 0)
                        {
                                /* -1 < x < 1, so result is +0 or -0. */
                                SET_FLOAT_WORD(ret, signbit);
                            }
                    else
                        {
                                SET_FLOAT_WORD(ret, signbit | (w & ~(0x007fffff >> exponent_less_127)));
                            }
                }
        else
            {
                    if (exponent_less_127 == 255)
                        /* x is NaN or infinite. */
                            return ret + ret;
            
                    /* All bits in the fraction field are relevant. */
                }
        return ret;
    }

/* 64-bit */
double opemu_trunc(double x)
{
        double ret = x;
        int signbit=0;
        /* Most significant word, least significant word. */
        int msw=0;
        unsigned int lsw=0;
        int exponent_less_1023=0;
    
        EXTRACT_WORDS(msw, lsw, ret);
    
        /* Extract sign bit. */
        signbit = msw & 0x80000000;
    
        /* Extract exponent field. */
        exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;
    
        if (exponent_less_1023 < 20)
            {
                    /* All significant digits are in msw. */
                    if (exponent_less_1023 < 0)
                        {
                                /* -1 < x < 1, so result is +0 or -0. */
                                INSERT_WORDS(ret, signbit, 0);
                            }
                    else
                        {
                                /* All relevant fraction bits are in msw, so lsw of the result is 0. */
                                INSERT_WORDS(ret, signbit | (msw & ~(0x000fffff >> exponent_less_1023)), 0);
                            }
                }
        else if (exponent_less_1023 > 51)
            {
                    if (exponent_less_1023 == 1024)
                        {
                                /* x is infinite, or not a number, so trigger an exception. */
                                return ret + ret;
                            }
                    /* All bits in the fraction fields of the msw and lsw are needed in the result. */
                }
        else
            {
                    /* All fraction bits in msw are relevant.  Truncate irrelevant
                               bits from lsw. */
                    INSERT_WORDS(ret, msw, lsw & ~(0xffffffffu >> (exponent_less_1023 - 20)));
                }
        return ret;
    }

/* 128-bit */
long double opemu_truncl(long double x)
{
        long double ret = x;
        uint64_t signbit;
        /* Most significant word, least significant word. */
        uint64_t msw=0;
        uint64_t lsw=0;
        int32_t exponent_less_16383=0;
    
        GET_LDOUBLE_WORDS(msw, lsw, ret);
    
        /* Extract sign bit. */
        signbit = msw & 0x8000000000000000ULL;
    
        /* Extract exponent field. */
        exponent_less_16383 = ((msw & 0x7fff000000000000ULL) >> 48) - 16383;
    
        if (exponent_less_16383 < 48)
            {
                    /* All significant digits are in msw. */
                    if (exponent_less_16383 < 0)
                        {
                                /* -1 < x < 1, so result is +0 or -0. */
                                SET_LDOUBLE_WORDS(ret, signbit, 0);
                            } else {
                                    /* All relevant fraction bits are in msw, so lsw of the result is 0. */
                                    SET_LDOUBLE_WORDS(ret, msw & ~(0x0000ffffffffffffLL >> exponent_less_16383), 0);
                                }
                }
        else if (exponent_less_16383 > 111)
            {
                    if (exponent_less_16383 == 16384)
                        {
                                /* x is infinite, or not a number, so trigger an exception. */
                                return ret + ret;
                            }
                    /* All bits in the fraction fields of the msw and lsw are needed in the result. */
                }
        else
            {
                    /* All fraction bits in msw are relevant.  Truncate irrelevant
                               bits from lsw. */
                    SET_LDOUBLE_WORDS(ret, msw, lsw & ~(0xffffffffffffffffULL >> (exponent_less_16383 - 48)));
                }
        
        return ret;
    }