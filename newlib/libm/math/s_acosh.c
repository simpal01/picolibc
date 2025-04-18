
/* @(#)e_acosh.c 5.1 93/09/24 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* acosh(x)
 * Method :
 *	Based on
 *		acosh(x) = log [ x + sqrt(x*x-1) ]
 *	we have
 *		acosh(x) := log(x)+ln2,	if x is large; else
 *		acosh(x) := log(2x-1/(sqrt(x*x-1)+x)) if x>2; else
 *		acosh(x) := log1p(t+sqrt(2.0*t+t*t)); where t=x-1.
 *
 * Special cases:
 *	acosh(x) is NaN with signal if x<1.
 *	acosh(NaN) is NaN without signal.
 */

#include "fdlibm.h"

#ifdef _NEED_FLOAT64

static const __float64
    one = _F_64(1.0),
    ln2 = _F_64(6.93147180559945286227e-01); /* 0x3FE62E42, 0xFEFA39EF */

__float64
acosh64(__float64 x)
{
    __float64 t;
    __int32_t hx;
    __uint32_t lx;
    EXTRACT_WORDS(hx, lx, x);
    if (hx < 0x3ff00000) { /* x < 1 */
        return __math_invalid(x);
    } else if (hx >= 0x41b00000) { /* x > 2**28 */
        if (hx >= 0x7ff00000) { /* x is inf of NaN */
            return x + x;
        } else
            return log64(x) + ln2; /* acosh(huge)=log(2x) */
    } else if ((((__uint32_t) hx - 0x3ff00000) | lx) == 0) {
        return _F_64(0.0); /* acosh(1) = 0 */
    } else if (hx > 0x40000000) { /* 2**28 > x > 2 */
        t = x * x;
        return log64(_F_64(2.0) * x - one / (x + sqrt64(t - one)));
    } else { /* 1<x<2 */
        t = x - one;
        return log1p64(t + sqrt64(_F_64(2.0) * t + t * t));
    }
}

_MATH_ALIAS_d_d(acosh)

#endif /* _NEED_FLOAT64 */
