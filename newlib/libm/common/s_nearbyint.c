/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */
/*
FUNCTION
<<nearbyint>>, <<nearbyintf>>---round to integer
INDEX
	nearbyint
INDEX
	nearbyintf

SYNOPSIS
	#include <math.h>
	double nearbyint(double <[x]>);
	float nearbyintf(float <[x]>);

DESCRIPTION
The <<nearbyint>> functions round their argument to an integer value in
floating-point format, using the current rounding direction and
(supposedly) without raising the "inexact" floating-point exception.
See the <<rint>> functions for the same function with the "inexact"
floating-point exception being raised when appropriate.

BUGS
Newlib does not support the floating-point exception model, so that
the floating-point exception control is not present and thereby what may
be seen will be compiler and hardware dependent in this regard.
The Newlib <<nearbyint>> functions are identical to the <<rint>>
functions with respect to the floating-point exception behavior, and
will cause the "inexact" exception to be raised for most targets.

RETURNS
<[x]> rounded to an integral value, using the current rounding direction.

PORTABILITY
ANSI C, POSIX

SEEALSO
<<rint>>, <<round>>
*/

#include <math.h>
#include "fdlibm.h"

#ifdef _NEED_FLOAT64

__float64
nearbyint64(__float64 x)
{
    if (isnan(x)) return x + x;
#if defined(FE_INEXACT) && !defined(__DOUBLE_NOEXCEPT)
    fenv_t env;
    fegetenv(&env);
#endif
    x = rint64(x);
#if defined(FE_INEXACT) && !defined(__DOUBLE_NOEXCEPT)
    fesetenv(&env);
#endif
    return x;
}

_MATH_ALIAS_d_d(nearbyint)

#endif /* _NEED_FLOAT64 */
