/* Copyright (c) 2009 Corinna Vinschen <corinna@vinschen.de> */
#include <wchar.h>
#include "local.h"

#ifdef _MB_CAPABLE
#ifdef _MB_EXTENDED_CHARSETS_ISO
/* Tables for the ISO-8859-x to UTF conversion.  The first index into the
   table is a value computed from the value x (function __iso_8859_index),
   the second index is the value of the incoming character - 0xa0.
   Values < 0xa0 don't have to be converted anyway. */
wchar_t __iso_8859_conv[14][0x60] = {
  /* ISO-8859-2 */
  { 0xa0, 0x104, 0x2d8, 0x141, 0xa4, 0x13d, 0x15a, 0xa7,
    0xa8, 0x160, 0x15e, 0x164, 0x179, 0xad, 0x17d, 0x17b,
    0xb0, 0x105, 0x2db, 0x142, 0xb4, 0x13e, 0x15b, 0x2c7,
    0xb8, 0x161, 0x15f, 0x165, 0x17a, 0x2dd, 0x17e, 0x17c,
    0x154, 0xc1, 0xc2, 0x102, 0xc4, 0x139, 0x106, 0xc7,
    0x10c, 0xc9, 0x118, 0xcb, 0x11a, 0xcd, 0xce, 0x10e,
    0x110, 0x143, 0x147, 0xd3, 0xd4, 0x150, 0xd6, 0xd7,
    0x158, 0x16e, 0xda, 0x170, 0xdc, 0xdd, 0x162, 0xdf,
    0x155, 0xe1, 0xe2, 0x103, 0xe4, 0x13a, 0x107, 0xe7,
    0x10d, 0xe9, 0x119, 0xeb, 0x11b, 0xed, 0xee, 0x10f,
    0x111, 0x144, 0x148, 0xf3, 0xf4, 0x151, 0xf6, 0xf7,
    0x159, 0x16f, 0xfa, 0x171, 0xfc, 0xfd, 0x163, 0x2d9 },
  /* ISO-8859-3 */
  { 0xa0, 0x126, 0x2d8, 0xa3, 0xa4, 0xf7f5, 0x124, 0xa7,
    0xa8, 0x130, 0x15e, 0x11e, 0x134, 0xad, 0xf7f6, 0x17b,
    0xb0, 0x127, 0xb2, 0xb3, 0xb4, 0xb5, 0x125, 0xb7,
    0xb8, 0x131, 0x15f, 0x11f, 0x135, 0xbd, 0xf7f7, 0x17c,
    0xc0, 0xc1, 0xc2, 0xf7f8, 0xc4, 0x10a, 0x108, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xf7f9, 0xd1, 0xd2, 0xd3, 0xd4, 0x120, 0xd6, 0xd7,
    0x11c, 0xd9, 0xda, 0xdb, 0xdc, 0x16c, 0x15c, 0xdf,
    0xe0, 0xe1, 0xe2, 0xf7fa, 0xe4, 0x10b, 0x109, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf7fb, 0xf1, 0xf2, 0xf3, 0xf4, 0x121, 0xf6, 0xf7,
    0x11d, 0xf9, 0xfa, 0xfb, 0xfc, 0x16d, 0x15d, 0x2d9 },
  /* ISO-8859-4 */
  { 0xa0, 0x104, 0x138, 0x156, 0xa4, 0x128, 0x13b, 0xa7,
    0xa8, 0x160, 0x112, 0x122, 0x166, 0xad, 0x17d, 0xaf,
    0xb0, 0x105, 0x2db, 0x157, 0xb4, 0x129, 0x13c, 0x2c7,
    0xb8, 0x161, 0x113, 0x123, 0x167, 0x14a, 0x17e, 0x14b,
    0x100, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0x12e,
    0x10c, 0xc9, 0x118, 0xcb, 0x116, 0xcd, 0xce, 0x12a,
    0x110, 0x145, 0x14c, 0x136, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0x172, 0xda, 0xdb, 0xdc, 0x168, 0x16a, 0xdf,
    0x101, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0x12f,
    0x10d, 0xe9, 0x119, 0xeb, 0x117, 0xed, 0xee, 0x12b,
    0x111, 0x146, 0x14d, 0x137, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0x173, 0xfa, 0xfb, 0xfc, 0x169, 0x16b, 0x2d9 },
  /* ISO-8859-5 */
  { 0xa0, 0x401, 0x402, 0x403, 0x404, 0x405, 0x406, 0x407,
    0x408, 0x409, 0x40a, 0x40b, 0x40c, 0xad, 0x40e, 0x40f,
    0x410, 0x411, 0x412, 0x413, 0x414, 0x415, 0x416, 0x417,
    0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f,
    0x420, 0x421, 0x422, 0x423, 0x424, 0x425, 0x426, 0x427,
    0x428, 0x429, 0x42a, 0x42b, 0x42c, 0x42d, 0x42e, 0x42f,
    0x430, 0x431, 0x432, 0x433, 0x434, 0x435, 0x436, 0x437,
    0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e, 0x43f,
    0x440, 0x441, 0x442, 0x443, 0x444, 0x445, 0x446, 0x447,
    0x448, 0x449, 0x44a, 0x44b, 0x44c, 0x44d, 0x44e, 0x44f,
    0x2116, 0x451, 0x452, 0x453, 0x454, 0x455, 0x456, 0x457,
    0x458, 0x459, 0x45a, 0x45b, 0x45c, 0xa7, 0x45e, 0x45f },
  /* ISO-8859-6 */
  { 0xa0, 0xf7c8, 0xf7c9, 0xf7ca, 0xa4, 0xf7cb, 0xf7cc, 0xf7cd,
    0xf7ce, 0xf7cf, 0xf7d0, 0xf7d1, 0x60c, 0xad, 0xf7d2, 0xf7d3,
    0xf7d4, 0xf7d5, 0xf7d6, 0xf7d7, 0xf7d8, 0xf7d9, 0xf7da, 0xf7db,
    0xf7dc, 0xf7dd, 0xf7de, 0x61b, 0xf7df, 0xf7e0, 0xf7e1, 0x61f,
    0xf7e2, 0x621, 0x622, 0x623, 0x624, 0x625, 0x626, 0x627,
    0x628, 0x629, 0x62a, 0x62b, 0x62c, 0x62d, 0x62e, 0x62f,
    0x630, 0x631, 0x632, 0x633, 0x634, 0x635, 0x636, 0x637,
    0x638, 0x639, 0x63a, 0xf7e3, 0xf7e4, 0xf7e5, 0xf7e6, 0xf7e7,
    0x640, 0x641, 0x642, 0x643, 0x644, 0x645, 0x646, 0x647,
    0x648, 0x649, 0x64a, 0x64b, 0x64c, 0x64d, 0x64e, 0x64f,
    0x650, 0x651, 0x652, 0xf7e8, 0xf7e9, 0xf7ea, 0xf7eb, 0xf7ec,
    0xf7ed, 0xf7ee, 0xf7ef, 0xf7f0, 0xf7f1, 0xf7f2, 0xf7f3, 0xf7f4 },
  /* ISO-8859-7 */
  { 0xa0, 0x2bd, 0x2bc, 0xa3, 0xf7c2, 0xf7c3, 0xa6, 0xa7,
    0xa8, 0xa9, 0xf7c4, 0xab, 0xac, 0xad, 0xf7c5, 0x2015,
    0xb0, 0xb1, 0xb2, 0xb3, 0x384, 0x385, 0x386, 0xb7,
    0x388, 0x389, 0x38a, 0xbb, 0x38c, 0xbd, 0x38e, 0x38f,
    0x390, 0x391, 0x392, 0x393, 0x394, 0x395, 0x396, 0x397,
    0x398, 0x399, 0x39a, 0x39b, 0x39c, 0x39d, 0x39e, 0x39f,
    0x3a0, 0x3a1, 0xf7c6, 0x3a3, 0x3a4, 0x3a5, 0x3a6, 0x3a7,
    0x3a8, 0x3a9, 0x3aa, 0x3ab, 0x3ac, 0x3ad, 0x3ae, 0x3af,
    0x3b0, 0x3b1, 0x3b2, 0x3b3, 0x3b4, 0x3b5, 0x3b6, 0x3b7,
    0x3b8, 0x3b9, 0x3ba, 0x3bb, 0x3bc, 0x3bd, 0x3be, 0x3bf,
    0x3c0, 0x3c1, 0x3c2, 0x3c3, 0x3c4, 0x3c5, 0x3c6, 0x3c7,
    0x3c8, 0x3c9, 0x3ca, 0x3cb, 0x3cc, 0x3cd, 0x3ce, 0xf7c7 },
  /* ISO-8859-8 */
  { 0xa0, 0xf79c, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xd7, 0xab, 0xac, 0xad, 0xae, 0x203e,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xf7, 0xbb, 0xbc, 0xbd, 0xbe, 0xf79d,
    0xf79e, 0xf79f, 0xf7a0, 0xf7a1, 0xf7a2, 0xf7a3, 0xf7a4, 0xf7a5,
    0xf7a6, 0xf7a7, 0xf7a8, 0xf7a9, 0xf7aa, 0xf7ab, 0xf7ac, 0xf7ad,
    0xf7ae, 0xf7af, 0xf7b0, 0xf7b1, 0xf7b2, 0xf7b3, 0xf7b4, 0xf7b5,
    0xf7b6, 0xf7b7, 0xf7b8, 0xf7b9, 0xf7ba, 0xf7bb, 0xf7bc, 0x2017,
    0x5d0, 0x5d1, 0x5d2, 0x5d3, 0x5d4, 0x5d5, 0x5d6, 0x5d7,
    0x5d8, 0x5d9, 0x5da, 0x5db, 0x5dc, 0x5dd, 0x5de, 0x5df,
    0x5e0, 0x5e1, 0x5e2, 0x5e3, 0x5e4, 0x5e5, 0x5e6, 0x5e7,
    0x5e8, 0x5e9, 0x5ea, 0xf7bd, 0xf7be, 0xf7bf, 0xf7c0, 0xf7c1 },
  /* ISO-8859-9 */
  { 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0x11e, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0x130, 0x15e, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0x11f, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0x131, 0x15f, 0xff },
  /* ISO-8859-10 */
  { 0xa0, 0x104, 0x112, 0x122, 0x12a, 0x128, 0x136, 0xa7,
    0x13b, 0x110, 0x160, 0x166, 0x17d, 0xad, 0x16a, 0x14a,
    0xb0, 0x105, 0x113, 0x123, 0x12b, 0x129, 0x137, 0xb7,
    0x13c, 0x111, 0x161, 0x167, 0x17e, 0x2015, 0x16b, 0x14b,
    0x100, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0x12e,
    0x10c, 0xc9, 0x118, 0xcb, 0x116, 0xcd, 0xce, 0xcf,
    0xd0, 0x145, 0x14c, 0xd3, 0xd4, 0xd5, 0xd6, 0x168,
    0xd8, 0x172, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0x101, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0x12f,
    0x10d, 0xe9, 0x119, 0xeb, 0x117, 0xed, 0xee, 0xef,
    0xf0, 0x146, 0x14d, 0xf3, 0xf4, 0xf5, 0xf6, 0x169,
    0xf8, 0x173, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0x138 },
  /* ISO-8859-11 */
  { 0xa0, 0xe01, 0xe02, 0xe03, 0xe04, 0xe05, 0xe06, 0xe07,
    0xe08, 0xe09, 0xe0a, 0xe0b, 0xe0c, 0xe0d, 0xe0e, 0xe0f,
    0xe10, 0xe11, 0xe12, 0xe13, 0xe14, 0xe15, 0xe16, 0xe17,
    0xe18, 0xe19, 0xe1a, 0xe1b, 0xe1c, 0xe1d, 0xe1e, 0xe1f,
    0xe20, 0xe21, 0xe22, 0xe23, 0xe24, 0xe25, 0xe26, 0xe27,
    0xe28, 0xe29, 0xe2a, 0xe2b, 0xe2c, 0xe2d, 0xe2e, 0xe2f,
    0xe30, 0xe31, 0xe32, 0xe33, 0xe34, 0xe35, 0xe36, 0xe37,
    0xe38, 0xe39, 0xe3a, 0xdb, 0xdc, 0xdd, 0xde, 0xe3f,
    0xe40, 0xe41, 0xe42, 0xe43, 0xe44, 0xe45, 0xe46, 0xe47,
    0xe48, 0xe49, 0xe4a, 0xe4b, 0xe4c, 0xe4d, 0xe4e, 0xe4f,
    0xe50, 0xe51, 0xe52, 0xe53, 0xe54, 0xe55, 0xe56, 0xe57,
    0xe58, 0xe59, 0xe5a, 0xe5b, 0xe31, 0xe34, 0xe47, 0xff },
  /* ISO-8859-12 doesn't exist.  The below code decrements the index
     into the table by one for ISO numbers > 12. */
  /* ISO-8859-13 */
  { 0xa0, 0x201d, 0xa2, 0xa3, 0xa4, 0x201e, 0xa6, 0xa7,
    0xd8, 0xa9, 0x156, 0xab, 0xac, 0xad, 0xae, 0xc6,
    0xb0, 0xb1, 0xb2, 0xb3, 0x201c, 0xb5, 0xb6, 0xb7,
    0xf8, 0xb9, 0x157, 0xbb, 0xbc, 0xbd, 0xbe, 0xe6,
    0x104, 0x12e, 0x100, 0x106, 0xc4, 0xc5, 0x118, 0x112,
    0x10c, 0xc9, 0x179, 0x116, 0x122, 0x136, 0x12a, 0x13b,
    0x160, 0x143, 0x145, 0xd3, 0x14c, 0xd5, 0xd6, 0xd7,
    0x172, 0x141, 0x15a, 0x16a, 0xdc, 0x17b, 0x17d, 0xdf,
    0x105, 0x12f, 0x101, 0x107, 0xe4, 0xe5, 0x119, 0x113,
    0x10d, 0xe9, 0x17a, 0x117, 0x123, 0x137, 0x12b, 0x13c,
    0x161, 0x144, 0x146, 0xf3, 0x14d, 0xf5, 0xf6, 0xf7,
    0x173, 0x142, 0x15b, 0x16b, 0xfc, 0x17c, 0x17e, 0x2019 },
  /* ISO-8859-14 */
  { 0xa0, 0x1e02, 0x1e03, 0xa3, 0x10a, 0x10b, 0x1e0a, 0xa7,
    0x1e80, 0xa9, 0x1e82, 0x1e0b, 0x1ef2, 0xad, 0xae, 0x178,
    0x1e1e, 0x1e1f, 0x120, 0x121, 0x1e40, 0x1e41, 0xb6, 0x1e56,
    0x1e81, 0x1e57, 0x1e83, 0x1e60, 0x1ef3, 0x1e84, 0x1e85, 0x1e61,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0x174, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0x1e6a,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0x176, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0x175, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0x1e6b,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0x177, 0xff },
  /* ISO-8859-15 */
  { 0xa0, 0xa1, 0xa2, 0xa3, 0x20ac, 0xa5, 0x160, 0xa7,
    0x161, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0x17d, 0xb5, 0xb6, 0xb7,
    0x17e, 0xb9, 0xba, 0xbb, 0x152, 0x153, 0x178, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
  /* ISO-8859-16 */
  { 0xa0, 0x104, 0x105, 0x141, 0x20ac, 0x201e, 0x160, 0xa7,
    0x161, 0xa9, 0x218, 0xab, 0x179, 0xad, 0x17a, 0x17b,
    0xb0, 0xb1, 0x10c, 0x142, 0x17d, 0x201d, 0xb6, 0xb7,
    0x17e, 0x10d, 0x219, 0xbb, 0x152, 0x153, 0x178, 0x17c,
    0xc0, 0xc1, 0xc2, 0x102, 0xc4, 0x106, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0x110, 0x143, 0xd2, 0xd3, 0xd4, 0x150, 0xd6, 0x15a,
    0x170, 0xd9, 0xda, 0xdb, 0xdc, 0x118, 0x21a, 0xdf,
    0xe0, 0xe1, 0xe2, 0x103, 0xe4, 0x107, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0x111, 0x144, 0xf2, 0xf3, 0xf4, 0x151, 0xf6, 0x15b,
    0x171, 0xf9, 0xfa, 0xfb, 0xfc, 0x119, 0x21b, 0xff }
};
#endif /* _MB_EXTENDED_CHARSETS_ISO */

#ifdef _MB_EXTENDED_CHARSETS_WINDOWS
/* Tables for the Windows default singlebyte ANSI codepage conversion.
   The first index into the table is a value computed from the codepage
   value (function __cp_index), the second index is the value of the
   incoming character - 0x80.
   Values < 0x80 don't have to be converted anyway. */
wchar_t __cp_conv[27][0x80] = {
  /* CP437 */
  { 0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0xe0, 0xe5, 0xe7,
    0xea, 0xeb, 0xe8, 0xef, 0xee, 0xec, 0xc4, 0xc5,
    0xc9, 0xe6, 0xc6, 0xf4, 0xf6, 0xf2, 0xfb, 0xf9,
    0xff, 0xd6, 0xdc, 0xa2, 0xa3, 0xa5, 0x20a7, 0x192,
    0xe1, 0xed, 0xf3, 0xfa, 0xf1, 0xd1, 0xaa, 0xba,
    0xbf, 0x2310, 0xac, 0xbd, 0xbc, 0xa1, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x3b1, 0xdf, 0x393, 0x3c0, 0x3a3, 0x3c3, 0xb5, 0x3c4,
    0x3a6, 0x398, 0x3a9, 0x3b4, 0x221e, 0x3c6, 0x3b5, 0x2229,
    0x2261, 0xb1, 0x2265, 0x2264, 0x2320, 0x2321, 0xf7, 0x2248,
    0xb0, 0x2219, 0xb7, 0x221a, 0x207f, 0xb2, 0x25a0, 0xa0 },
  /* CP720 */
  { 0x80, 0x81, 0xe9, 0xe2, 0x84, 0xe0, 0x86, 0xe7,
    0xea, 0xeb, 0xe8, 0xef, 0xee, 0x8d, 0x8e, 0x8f,
    0x90, 0x651, 0x652, 0xf4, 0xa4, 0x640, 0xfb, 0xf9,
    0x621, 0x622, 0x623, 0x624, 0xa3, 0x625, 0x626, 0x627,
    0x628, 0x629, 0x62a, 0x62b, 0x62c, 0x62d, 0x62e, 0x62f,
    0x630, 0x631, 0x632, 0x633, 0x634, 0x635, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x636, 0x637, 0x638, 0x639, 0x63a, 0x641, 0xb5, 0x642,
    0x643, 0x644, 0x645, 0x646, 0x647, 0x648, 0x649, 0x64a,
    0x2261, 0x64b, 0x64c, 0x64d, 0x64e, 0x64f, 0x650, 0x2248,
    0xb0, 0x2219, 0xb7, 0x221a, 0x207f, 0xb2, 0x25a0, 0xa0 },
  /* CP737 */
  { 0x391, 0x392, 0x393, 0x394, 0x395, 0x396, 0x397, 0x398,
    0x399, 0x39a, 0x39b, 0x39c, 0x39d, 0x39e, 0x39f, 0x3a0,
    0x3a1, 0x3a3, 0x3a4, 0x3a5, 0x3a6, 0x3a7, 0x3a8, 0x3a9,
    0x3b1, 0x3b2, 0x3b3, 0x3b4, 0x3b5, 0x3b6, 0x3b7, 0x3b8,
    0x3b9, 0x3ba, 0x3bb, 0x3bc, 0x3bd, 0x3be, 0x3bf, 0x3c0,
    0x3c1, 0x3c3, 0x3c2, 0x3c4, 0x3c5, 0x3c6, 0x3c7, 0x3c8,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x3c9, 0x3ac, 0x3ad, 0x3ae, 0x3ca, 0x3af, 0x3cc, 0x3cd,
    0x3cb, 0x3ce, 0x386, 0x388, 0x389, 0x38a, 0x38c, 0x38e,
    0x38f, 0xb1, 0x2265, 0x2264, 0x3aa, 0x3ab, 0xf7, 0x2248,
    0xb0, 0x2219, 0xb7, 0x221a, 0x207f, 0xb2, 0x25a0, 0xa0 },
  /* CP775 */
  { 0x106, 0xfc, 0xe9, 0x101, 0xe4, 0x123, 0xe5, 0x107,
    0x142, 0x113, 0x156, 0x157, 0x12b, 0x179, 0xc4, 0xc5,
    0xc9, 0xe6, 0xc6, 0x14d, 0xf6, 0x122, 0xa2, 0x15a,
    0x15b, 0xd6, 0xdc, 0xf8, 0xa3, 0xd8, 0xd7, 0xa4,
    0x100, 0x12a, 0xf3, 0x17b, 0x17c, 0x17a, 0x201d, 0xa6,
    0xa9, 0xae, 0xac, 0xbd, 0xbc, 0x141, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x104, 0x10c, 0x118,
    0x116, 0x2563, 0x2551, 0x2557, 0x255d, 0x12e, 0x160, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x172, 0x16a,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x17d,
    0x105, 0x10d, 0x119, 0x117, 0x12f, 0x161, 0x173, 0x16b,
    0x17e, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0xd3, 0xdf, 0x14c, 0x143, 0xf5, 0xd5, 0xb5, 0x144,
    0x136, 0x137, 0x13b, 0x13c, 0x146, 0x112, 0x145, 0x2019,
    0xad, 0xb1, 0x201c, 0xbe, 0xb6, 0xa7, 0xf7, 0x201e,
    0xb0, 0x2219, 0xb7, 0xb9, 0xb3, 0xb2, 0x25a0, 0xa0 },
  /* CP850 */
  { 0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0xe0, 0xe5, 0xe7,
    0xea, 0xeb, 0xe8, 0xef, 0xee, 0xec, 0xc4, 0xc5,
    0xc9, 0xe6, 0xc6, 0xf4, 0xf6, 0xf2, 0xfb, 0xf9,
    0xff, 0xd6, 0xdc, 0xf8, 0xa3, 0xd8, 0xd7, 0x192,
    0xe1, 0xed, 0xf3, 0xfa, 0xf1, 0xd1, 0xaa, 0xba,
    0xbf, 0xae, 0xac, 0xbd, 0xbc, 0xa1, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0xc1, 0xc2, 0xc0,
    0xa9, 0x2563, 0x2551, 0x2557, 0x255d, 0xa2, 0xa5, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0xe3, 0xc3,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0xa4,
    0xf0, 0xd0, 0xca, 0xcb, 0xc8, 0x131, 0xcd, 0xce,
    0xcf, 0x2518, 0x250c, 0x2588, 0x2584, 0xa6, 0xcc, 0x2580,
    0xd3, 0xdf, 0xd4, 0xd2, 0xf5, 0xd5, 0xb5, 0xfe,
    0xde, 0xda, 0xdb, 0xd9, 0xfd, 0xdd, 0xaf, 0xb4,
    0xad, 0xb1, 0x2017, 0xbe, 0xb6, 0xa7, 0xf7, 0xb8,
    0xb0, 0xa8, 0xb7, 0xb9, 0xb3, 0xb2, 0x25a0, 0xa0 },
  /* CP852 */
  { 0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0x16f, 0x107, 0xe7,
    0x142, 0xeb, 0x150, 0x151, 0xee, 0x179, 0xc4, 0x106,
    0xc9, 0x139, 0x13a, 0xf4, 0xf6, 0x13d, 0x13e, 0x15a,
    0x15b, 0xd6, 0xdc, 0x164, 0x165, 0x141, 0xd7, 0x10d,
    0xe1, 0xed, 0xf3, 0xfa, 0x104, 0x105, 0x17d, 0x17e,
    0x118, 0x119, 0xac, 0x17a, 0x10c, 0x15f, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0xc1, 0xc2, 0x11a,
    0x15e, 0x2563, 0x2551, 0x2557, 0x255d, 0x17b, 0x17c, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x102, 0x103,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0xa4,
    0x111, 0x110, 0x10e, 0xcb, 0x10f, 0x147, 0xcd, 0xce,
    0x11b, 0x2518, 0x250c, 0x2588, 0x2584, 0x162, 0x16e, 0x2580,
    0xd3, 0xdf, 0xd4, 0x143, 0x144, 0x148, 0x160, 0x161,
    0x154, 0xda, 0x155, 0x170, 0xfd, 0xdd, 0x163, 0xb4,
    0xad, 0x2dd, 0x2db, 0x2c7, 0x2d8, 0xa7, 0xf7, 0xb8,
    0xb0, 0xa8, 0x2d9, 0x171, 0x158, 0x159, 0x25a0, 0xa0 },
  /* CP855 */
  { 0x452, 0x402, 0x453, 0x403, 0x451, 0x401, 0x454, 0x404,
    0x455, 0x405, 0x456, 0x406, 0x457, 0x407, 0x458, 0x408,
    0x459, 0x409, 0x45a, 0x40a, 0x45b, 0x40b, 0x45c, 0x40c,
    0x45e, 0x40e, 0x45f, 0x40f, 0x44e, 0x42e, 0x44a, 0x42a,
    0x430, 0x410, 0x431, 0x411, 0x446, 0x426, 0x434, 0x414,
    0x435, 0x415, 0x444, 0x424, 0x433, 0x413, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x445, 0x425, 0x438,
    0x418, 0x2563, 0x2551, 0x2557, 0x255d, 0x439, 0x419, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x43a, 0x41a,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0xa4,
    0x43b, 0x41b, 0x43c, 0x41c, 0x43d, 0x41d, 0x43e, 0x41e,
    0x43f, 0x2518, 0x250c, 0x2588, 0x2584, 0x41f, 0x44f, 0x2580,
    0x42f, 0x440, 0x420, 0x441, 0x421, 0x442, 0x422, 0x443,
    0x423, 0x436, 0x416, 0x432, 0x412, 0x44c, 0x42c, 0x2116,
    0xad, 0x44b, 0x42b, 0x437, 0x417, 0x448, 0x428, 0x44d,
    0x42d, 0x449, 0x429, 0x447, 0x427, 0xa7, 0x25a0, 0xa0 },
  /* CP857 */
  { 0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0xe0, 0xe5, 0xe7,
    0xea, 0xeb, 0xe8, 0xef, 0xee, 0x131, 0xc4, 0xc5,
    0xc9, 0xe6, 0xc6, 0xf4, 0xf6, 0xf2, 0xfb, 0xf9,
    0x130, 0xd6, 0xdc, 0xf8, 0xa3, 0xd8, 0x15e, 0x15f,
    0xe1, 0xed, 0xf3, 0xfa, 0xf1, 0xd1, 0x11e, 0x11f,
    0xbf, 0xae, 0xac, 0xbd, 0xbc, 0xa1, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0xc1, 0xc2, 0xc0,
    0xa9, 0x2563, 0x2551, 0x2557, 0x255d, 0xa2, 0xa5, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0xe3, 0xc3,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0xa4,
    0xba, 0xaa, 0xca, 0xcb, 0xc8, 0xf8bb, 0xcd, 0xce,
    0xcf, 0x2518, 0x250c, 0x2588, 0x2584, 0xa6, 0xcc, 0x2580,
    0xd3, 0xdf, 0xd4, 0xd2, 0xf5, 0xd5, 0xb5, 0xf8bc,
    0xd7, 0xda, 0xdb, 0xd9, 0xec, 0xff, 0xaf, 0xb4,
    0xad, 0xb1, 0xf8bd, 0xbe, 0xb6, 0xa7, 0xf7, 0xb8,
    0xb0, 0xa8, 0xb7, 0xb9, 0xb3, 0xb2, 0x25a0, 0xa0 },
  /* CP858 */
  { 0xc7, 0xfc, 0xe9, 0xe2, 0xe4, 0xe0, 0xe5, 0xe7,
    0xea, 0xeb, 0xe8, 0xef, 0xee, 0xec, 0xc4, 0xc5,
    0xc9, 0xe6, 0xc6, 0xf4, 0xf6, 0xf2, 0xfb, 0xf9,
    0xff, 0xd6, 0xdc, 0xf8, 0xa3, 0xd8, 0xd7, 0x192,
    0xe1, 0xed, 0xf3, 0xfa, 0xf1, 0xd1, 0xaa, 0xba,
    0xbf, 0xae, 0xac, 0xbd, 0xbc, 0xa1, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0xc1, 0xc2, 0xc0,
    0xa9, 0x2563, 0x2551, 0x2557, 0x255d, 0xa2, 0xa5, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0xe3, 0xc3,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0xa4,
    0xf0, 0xd0, 0xca, 0xcb, 0xc8, 0x20ac, 0xcd, 0xce,
    0xcf, 0x2518, 0x250c, 0x2588, 0x2584, 0xa6, 0xcc, 0x2580,
    0xd3, 0xdf, 0xd4, 0xd2, 0xf5, 0xd5, 0xb5, 0xfe,
    0xde, 0xda, 0xdb, 0xd9, 0xfd, 0xdd, 0xaf, 0xb4,
    0xad, 0xb1, 0x2017, 0xbe, 0xb6, 0xa7, 0xf7, 0xb8,
    0xb0, 0xa8, 0xb7, 0xb9, 0xb3, 0xb2, 0x25a0, 0xa0 },
  /* CP862 */
  { 0x5d0, 0x5d1, 0x5d2, 0x5d3, 0x5d4, 0x5d5, 0x5d6, 0x5d7,
    0x5d8, 0x5d9, 0x5da, 0x5db, 0x5dc, 0x5dd, 0x5de, 0x5df,
    0x5e0, 0x5e1, 0x5e2, 0x5e3, 0x5e4, 0x5e5, 0x5e6, 0x5e7,
    0x5e8, 0x5e9, 0x5ea, 0xa2, 0xa3, 0xa5, 0x20a7, 0x192,
    0xe1, 0xed, 0xf3, 0xfa, 0xf1, 0xd1, 0xaa, 0xba,
    0xbf, 0x2310, 0xac, 0xbd, 0xbc, 0xa1, 0xab, 0xbb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x3b1, 0xdf, 0x393, 0x3c0, 0x3a3, 0x3c3, 0xb5, 0x3c4,
    0x3a6, 0x398, 0x3a9, 0x3b4, 0x221e, 0x3c6, 0x3b5, 0x2229,
    0x2261, 0xb1, 0x2265, 0x2264, 0x2320, 0x2321, 0xf7, 0x2248,
    0xb0, 0x2219, 0xb7, 0x221a, 0x207f, 0xb2, 0x25a0, 0xa0 },
  /* CP866 */
  { 0x410, 0x411, 0x412, 0x413, 0x414, 0x415, 0x416, 0x417,
    0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f,
    0x420, 0x421, 0x422, 0x423, 0x424, 0x425, 0x426, 0x427,
    0x428, 0x429, 0x42a, 0x42b, 0x42c, 0x42d, 0x42e, 0x42f,
    0x430, 0x431, 0x432, 0x433, 0x434, 0x435, 0x436, 0x437,
    0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e, 0x43f,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x440, 0x441, 0x442, 0x443, 0x444, 0x445, 0x446, 0x447,
    0x448, 0x449, 0x44a, 0x44b, 0x44c, 0x44d, 0x44e, 0x44f,
    0x401, 0x451, 0x404, 0x454, 0x407, 0x457, 0x40e, 0x45e,
    0xb0, 0x2219, 0xb7, 0x221a, 0x2116, 0xa4, 0x25a0, 0xa0 },
  /* CP874 */
  { 0x20ac, 0x81, 0x82, 0x83, 0x84, 0x2026, 0x86, 0x87,
    0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xe01, 0xe02, 0xe03, 0xe04, 0xe05, 0xe06, 0xe07,
    0xe08, 0xe09, 0xe0a, 0xe0b, 0xe0c, 0xe0d, 0xe0e, 0xe0f,
    0xe10, 0xe11, 0xe12, 0xe13, 0xe14, 0xe15, 0xe16, 0xe17,
    0xe18, 0xe19, 0xe1a, 0xe1b, 0xe1c, 0xe1d, 0xe1e, 0xe1f,
    0xe20, 0xe21, 0xe22, 0xe23, 0xe24, 0xe25, 0xe26, 0xe27,
    0xe28, 0xe29, 0xe2a, 0xe2b, 0xe2c, 0xe2d, 0xe2e, 0xe2f,
    0xe30, 0xe31, 0xe32, 0xe33, 0xe34, 0xe35, 0xe36, 0xe37,
    0xe38, 0xe39, 0xe3a, 0xf8c1, 0xf8c2, 0xf8c3, 0xf8c4, 0xe3f,
    0xe40, 0xe41, 0xe42, 0xe43, 0xe44, 0xe45, 0xe46, 0xe47,
    0xe48, 0xe49, 0xe4a, 0xe4b, 0xe4c, 0xe4d, 0xe4e, 0xe4f,
    0xe50, 0xe51, 0xe52, 0xe53, 0xe54, 0xe55, 0xe56, 0xe57,
    0xe58, 0xe59, 0xe5a, 0xe5b, 0xf8c5, 0xf8c6, 0xf8c7, 0xf8c8 },
  /* CP1125 */
  { 0x410, 0x411, 0x412, 0x413, 0x414, 0x415, 0x416, 0x417,
    0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f,
    0x420, 0x421, 0x422, 0x423, 0x424, 0x425, 0x426, 0x427,
    0x428, 0x429, 0x42a, 0x42b, 0x42c, 0x42d, 0x42e, 0x42f,
    0x430, 0x431, 0x432, 0x433, 0x434, 0x435, 0x436, 0x437,
    0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e, 0x43f,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x440, 0x441, 0x442, 0x443, 0x444, 0x445, 0x446, 0x447,
    0x448, 0x449, 0x44a, 0x44b, 0x44c, 0x44d, 0x44e, 0x44f,
    0x401, 0x451, 0x490, 0x491, 0x404, 0x454, 0x406, 0x456,
    0x407, 0x457, 0xb7, 0x221a, 0x2116, 0xa4, 0x25a0, 0xa0 },
  /* CP1250 */
  { 0x20ac, 0x81, 0x201a, 0x83, 0x201e, 0x2026, 0x2020, 0x2021,
    0x88, 0x2030, 0x160, 0x2039, 0x15a, 0x164, 0x17d, 0x179,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x2122, 0x161, 0x203a, 0x15b, 0x165, 0x17e, 0x17a,
    0xa0, 0x2c7, 0x2d8, 0x141, 0xa4, 0x104, 0xa6, 0xa7,
    0xa8, 0xa9, 0x15e, 0xab, 0xac, 0xad, 0xae, 0x17b,
    0xb0, 0xb1, 0x2db, 0x142, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0x105, 0x15f, 0xbb, 0x13d, 0x2dd, 0x13e, 0x17c,
    0x154, 0xc1, 0xc2, 0x102, 0xc4, 0x139, 0x106, 0xc7,
    0x10c, 0xc9, 0x118, 0xcb, 0x11a, 0xcd, 0xce, 0x10e,
    0x110, 0x143, 0x147, 0xd3, 0xd4, 0x150, 0xd6, 0xd7,
    0x158, 0x16e, 0xda, 0x170, 0xdc, 0xdd, 0x162, 0xdf,
    0x155, 0xe1, 0xe2, 0x103, 0xe4, 0x13a, 0x107, 0xe7,
    0x10d, 0xe9, 0x119, 0xeb, 0x11b, 0xed, 0xee, 0x10f,
    0x111, 0x144, 0x148, 0xf3, 0xf4, 0x151, 0xf6, 0xf7,
    0x159, 0x16f, 0xfa, 0x171, 0xfc, 0xfd, 0x163, 0x2d9 },
  /* CP1251 */
  { 0x402, 0x403, 0x201a, 0x453, 0x201e, 0x2026, 0x2020, 0x2021,
    0x20ac, 0x2030, 0x409, 0x2039, 0x40a, 0x40c, 0x40b, 0x40f,
    0x452, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x2122, 0x459, 0x203a, 0x45a, 0x45c, 0x45b, 0x45f,
    0xa0, 0x40e, 0x45e, 0x408, 0xa4, 0x490, 0xa6, 0xa7,
    0x401, 0xa9, 0x404, 0xab, 0xac, 0xad, 0xae, 0x407,
    0xb0, 0xb1, 0x406, 0x456, 0x491, 0xb5, 0xb6, 0xb7,
    0x451, 0x2116, 0x454, 0xbb, 0x458, 0x405, 0x455, 0x457,
    0x410, 0x411, 0x412, 0x413, 0x414, 0x415, 0x416, 0x417,
    0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f,
    0x420, 0x421, 0x422, 0x423, 0x424, 0x425, 0x426, 0x427,
    0x428, 0x429, 0x42a, 0x42b, 0x42c, 0x42d, 0x42e, 0x42f,
    0x430, 0x431, 0x432, 0x433, 0x434, 0x435, 0x436, 0x437,
    0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e, 0x43f,
    0x440, 0x441, 0x442, 0x443, 0x444, 0x445, 0x446, 0x447,
    0x448, 0x449, 0x44a, 0x44b, 0x44c, 0x44d, 0x44e, 0x44f },
  /* CP1252 */
  { 0x20ac, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x160, 0x2039, 0x152, 0x8d, 0x17d, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x2dc, 0x2122, 0x161, 0x203a, 0x153, 0x9d, 0x17e, 0x178,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
  /* CP1253 */
  { 0x20ac, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x88, 0x2030, 0x8a, 0x2039, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x2122, 0x9a, 0x203a, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0x385, 0x386, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xf8f9, 0xab, 0xac, 0xad, 0xae, 0x2015,
    0xb0, 0xb1, 0xb2, 0xb3, 0x384, 0xb5, 0xb6, 0xb7,
    0x388, 0x389, 0x38a, 0xbb, 0x38c, 0xbd, 0x38e, 0x38f,
    0x390, 0x391, 0x392, 0x393, 0x394, 0x395, 0x396, 0x397,
    0x398, 0x399, 0x39a, 0x39b, 0x39c, 0x39d, 0x39e, 0x39f,
    0x3a0, 0x3a1, 0xf8fa, 0x3a3, 0x3a4, 0x3a5, 0x3a6, 0x3a7,
    0x3a8, 0x3a9, 0x3aa, 0x3ab, 0x3ac, 0x3ad, 0x3ae, 0x3af,
    0x3b0, 0x3b1, 0x3b2, 0x3b3, 0x3b4, 0x3b5, 0x3b6, 0x3b7,
    0x3b8, 0x3b9, 0x3ba, 0x3bb, 0x3bc, 0x3bd, 0x3be, 0x3bf,
    0x3c0, 0x3c1, 0x3c2, 0x3c3, 0x3c4, 0x3c5, 0x3c6, 0x3c7,
    0x3c8, 0x3c9, 0x3ca, 0x3cb, 0x3cc, 0x3cd, 0x3ce, 0xf8fb },
  /* CP1254 */
  { 0x20ac, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x160, 0x2039, 0x152, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x2dc, 0x2122, 0x161, 0x203a, 0x153, 0x9d, 0x9e, 0x178,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0x11e, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0x130, 0x15e, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0x11f, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0x131, 0x15f, 0xff },
  /* CP1255 */
  { 0x20ac, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x8a, 0x2039, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x2dc, 0x2122, 0x9a, 0x203a, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xa1, 0xa2, 0xa3, 0x20aa, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xd7, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xf7, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0x5b0, 0x5b1, 0x5b2, 0x5b3, 0x5b4, 0x5b5, 0x5b6, 0x5b7,
    0x5b8, 0x5b9, 0x5ba, 0x5bb, 0x5bc, 0x5bd, 0x5be, 0x5bf,
    0x5c0, 0x5c1, 0x5c2, 0x5c3, 0x5f0, 0x5f1, 0x5f2, 0x5f3,
    0x5f4, 0xf88d, 0xf88e, 0xf88f, 0xf890, 0xf891, 0xf892, 0xf893,
    0x5d0, 0x5d1, 0x5d2, 0x5d3, 0x5d4, 0x5d5, 0x5d6, 0x5d7,
    0x5d8, 0x5d9, 0x5da, 0x5db, 0x5dc, 0x5dd, 0x5de, 0x5df,
    0x5e0, 0x5e1, 0x5e2, 0x5e3, 0x5e4, 0x5e5, 0x5e6, 0x5e7,
    0x5e8, 0x5e9, 0x5ea, 0xf894, 0xf895, 0x200e, 0x200f, 0xf896 },
  /* CP1256 */
  { 0x20ac, 0x67e, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x679, 0x2039, 0x152, 0x686, 0x698, 0x688,
    0x6af, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x6a9, 0x2122, 0x691, 0x203a, 0x153, 0x200c, 0x200d, 0x6ba,
    0xa0, 0x60c, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0x6be, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0x61b, 0xbb, 0xbc, 0xbd, 0xbe, 0x61f,
    0x6c1, 0x621, 0x622, 0x623, 0x624, 0x625, 0x626, 0x627,
    0x628, 0x629, 0x62a, 0x62b, 0x62c, 0x62d, 0x62e, 0x62f,
    0x630, 0x631, 0x632, 0x633, 0x634, 0x635, 0x636, 0xd7,
    0x637, 0x638, 0x639, 0x63a, 0x640, 0x641, 0x642, 0x643,
    0xe0, 0x644, 0xe2, 0x645, 0x646, 0x647, 0x648, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0x649, 0x64a, 0xee, 0xef,
    0x64b, 0x64c, 0x64d, 0x64e, 0xf4, 0x64f, 0x650, 0xf7,
    0x651, 0xf9, 0x652, 0xfb, 0xfc, 0x200e, 0x200f, 0x6d2 },
  /* CP1257 */
  { 0x20ac, 0x81, 0x201a, 0x83, 0x201e, 0x2026, 0x2020, 0x2021,
    0x88, 0x2030, 0x8a, 0x2039, 0x8c, 0xa8, 0x2c7, 0xb8,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x2122, 0x9a, 0x203a, 0x9c, 0xaf, 0x2db, 0x9f,
    0xa0, 0xf8fc, 0xa2, 0xa3, 0xa4, 0xf8fd, 0xa6, 0xa7,
    0xd8, 0xa9, 0x156, 0xab, 0xac, 0xad, 0xae, 0xc6,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xf8, 0xb9, 0x157, 0xbb, 0xbc, 0xbd, 0xbe, 0xe6,
    0x104, 0x12e, 0x100, 0x106, 0xc4, 0xc5, 0x118, 0x112,
    0x10c, 0xc9, 0x179, 0x116, 0x122, 0x136, 0x12a, 0x13b,
    0x160, 0x143, 0x145, 0xd3, 0x14c, 0xd5, 0xd6, 0xd7,
    0x172, 0x141, 0x15a, 0x16a, 0xdc, 0x17b, 0x17d, 0xdf,
    0x105, 0x12f, 0x101, 0x107, 0xe4, 0xe5, 0x119, 0x113,
    0x10d, 0xe9, 0x17a, 0x117, 0x123, 0x137, 0x12b, 0x13c,
    0x161, 0x144, 0x146, 0xf3, 0x14d, 0xf5, 0xf6, 0xf7,
    0x173, 0x142, 0x15b, 0x16b, 0xfc, 0x17c, 0x17e, 0x2d9 },
  /* CP1258 */
  { 0x20ac, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x8a, 0x2039, 0x152, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x2dc, 0x2122, 0x9a, 0x203a, 0x153, 0x9d, 0x9e, 0x178,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0x102, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0x300, 0xcd, 0xce, 0xcf,
    0x110, 0xd1, 0x309, 0xd3, 0xd4, 0x1a0, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0x1af, 0x303, 0xdf,
    0xe0, 0xe1, 0xe2, 0x103, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0x301, 0xed, 0xee, 0xef,
    0x111, 0xf1, 0x323, 0xf3, 0xf4, 0x1a1, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0x1b0, 0x20ab, 0xff },
  /* CP20866 (KOI8-R) */
  { 0x2500, 0x2502, 0x250c, 0x2510, 0x2514, 0x2518, 0x251c, 0x2524,
    0x252c, 0x2534, 0x253c, 0x2580, 0x2584, 0x2588, 0x258c, 0x2590,
    0x2591, 0x2592, 0x2593, 0x2320, 0x25a0, 0x2219, 0x221a, 0x2248,
    0x2264, 0x2265, 0xa0, 0x2321, 0xb0, 0xb2, 0xb7, 0xf7,
    0x2550, 0x2551, 0x2552, 0x451, 0x2553, 0x2554, 0x2555, 0x2556,
    0x2557, 0x2558, 0x2559, 0x255a, 0x255b, 0x255c, 0x255d, 0x255e,
    0x255f, 0x2560, 0x2561, 0x401, 0x2562, 0x2563, 0x2564, 0x2565,
    0x2566, 0x2567, 0x2568, 0x2569, 0x256a, 0x256b, 0x256c, 0xa9,
    0x44e, 0x430, 0x431, 0x446, 0x434, 0x435, 0x444, 0x433,
    0x445, 0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e,
    0x43f, 0x44f, 0x440, 0x441, 0x442, 0x443, 0x436, 0x432,
    0x44c, 0x44b, 0x437, 0x448, 0x44d, 0x449, 0x447, 0x44a,
    0x42e, 0x410, 0x411, 0x426, 0x414, 0x415, 0x424, 0x413,
    0x425, 0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e,
    0x41f, 0x42f, 0x420, 0x421, 0x422, 0x423, 0x416, 0x412,
    0x42c, 0x42b, 0x417, 0x428, 0x42d, 0x429, 0x427, 0x42a },
  /* CP21866 (KOI8-U) */
  { 0x2500, 0x2502, 0x250c, 0x2510, 0x2514, 0x2518, 0x251c, 0x2524,
    0x252c, 0x2534, 0x253c, 0x2580, 0x2584, 0x2588, 0x258c, 0x2590,
    0x2591, 0x2592, 0x2593, 0x2320, 0x25a0, 0x2219, 0x221a, 0x2248,
    0x2264, 0x2265, 0xa0, 0x2321, 0xb0, 0xb2, 0xb7, 0xf7,
    0x2550, 0x2551, 0x2552, 0x451, 0x454, 0x2554, 0x456, 0x457,
    0x2557, 0x2558, 0x2559, 0x255a, 0x255b, 0x491, 0x45e, 0x255e,
    0x255f, 0x2560, 0x2561, 0x401, 0x404, 0x2563, 0x406, 0x407,
    0x2566, 0x2567, 0x2568, 0x2569, 0x256a, 0x490, 0x40e, 0xa9,
    0x44e, 0x430, 0x431, 0x446, 0x434, 0x435, 0x444, 0x433,
    0x445, 0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e,
    0x43f, 0x44f, 0x440, 0x441, 0x442, 0x443, 0x436, 0x432,
    0x44c, 0x44b, 0x437, 0x448, 0x44d, 0x449, 0x447, 0x44a,
    0x42e, 0x410, 0x411, 0x426, 0x414, 0x415, 0x424, 0x413,
    0x425, 0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e,
    0x41f, 0x42f, 0x420, 0x421, 0x422, 0x423, 0x416, 0x412,
    0x42c, 0x42b, 0x417, 0x428, 0x42d, 0x429, 0x427, 0x42a },
  /* The following are not valid Windows codepages, but they fit nicely here.
     The CP numbers are only used internally and are guranteed not to clash
     with valid Windows codepage identifier. */
  /* CP101 (GEORGIAN-PS)  Georgian charset, used as the default charset in
     the ka_GE locale (Georgian, Georgia).  Apparently derived from Windows
     CP1252. */
  { 0x80, 0x81, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x2c6, 0x2030, 0x160, 0x2039, 0x152, 0x8d, 0x8e, 0x8f,
    0x90, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x2dc, 0x2122, 0x161, 0x203a, 0x153, 0x9d, 0x9e, 0x178,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0x10d0, 0x10d1, 0x10d2, 0x10d3, 0x10d4, 0x10d5, 0x10d6, 0x10f1,
    0x10d7, 0x10d8, 0x10d9, 0x10da, 0x10db, 0x10dc, 0x10f2, 0x10dd,
    0x10de, 0x10df, 0x10e0, 0x10e1, 0x10e2, 0x10f3, 0x10e3, 0x10e4,
    0x10e5, 0x10e6, 0x10e7, 0x10e8, 0x10e9, 0x10ea, 0x10eb, 0x10ec,
    0x10ed, 0x10ee, 0x10f4, 0x10ef, 0x10f0, 0x10f5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff },
  /* CP102 (PT154) Cyrillic-Asian charset, used as the default charset in
     the kk_KZ locale (Kazakh, Kazakhstan). */
  { 0x496, 0x492, 0x4ee, 0x493, 0x201e, 0x2026, 0x4b6, 0x4ae,
    0x4b2, 0x4af, 0x4a0, 0x4e2, 0x4a2, 0x49a, 0x4ba, 0x4b8,
    0x497, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x4b3, 0x4b7, 0x4a1, 0x4e3, 0x4a3, 0x49b, 0x4bb, 0x4b9,
    0xa0, 0x40e, 0x45e, 0x408, 0x4e8, 0x498, 0x4b0, 0xa7,
    0x401, 0xa9, 0x4d8, 0xab, 0xac, 0x4ef, 0xae, 0x49c,
    0xb0, 0x4b1, 0x406, 0x456, 0x499, 0x4e9, 0xb6, 0xb7,
    0x451, 0x2116, 0x4d9, 0xbb, 0x458, 0x4aa, 0x4ab, 0x49d,
    0x410, 0x411, 0x412, 0x413, 0x414, 0x415, 0x416, 0x417,
    0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f,
    0x420, 0x421, 0x422, 0x423, 0x424, 0x425, 0x426, 0x427,
    0x428, 0x429, 0x42a, 0x42b, 0x42c, 0x42d, 0x42e, 0x42f,
    0x430, 0x431, 0x432, 0x433, 0x434, 0x435, 0x436, 0x437,
    0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e, 0x43f,
    0x440, 0x441, 0x442, 0x443, 0x444, 0x445, 0x446, 0x447,
    0x448, 0x449, 0x44a, 0x44b, 0x44c, 0x44d, 0x44e, 0x44f },
  /* CP103 (KOI8-T) */
  { 0x049b, 0x0493, 0x201a, 0x0492, 0x201e, 0x2026, 0x2020, 0x2021,
    0x88, 0x2030, 0x04b3, 0x2039, 0x04b2, 0x04b7, 0x04b6, 0x8f,
    0x049a, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x98, 0x2122, 0x9a, 0x203a, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0x04ef, 0x04ee, 0x0451, 0xa4, 0x04e3, 0xa6, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0x401, 0xb4, 0x04e2, 0xb6, 0xb7,
    0xb8, 0x2116, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xa9,
    0x44e, 0x430, 0x431, 0x446, 0x434, 0x435, 0x444, 0x433,
    0x445, 0x438, 0x439, 0x43a, 0x43b, 0x43c, 0x43d, 0x43e,
    0x43f, 0x44f, 0x440, 0x441, 0x442, 0x443, 0x436, 0x432,
    0x44c, 0x44b, 0x437, 0x448, 0x44d, 0x449, 0x447, 0x44a,
    0x42e, 0x410, 0x411, 0x426, 0x414, 0x415, 0x424, 0x413,
    0x425, 0x418, 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e,
    0x41f, 0x42f, 0x420, 0x421, 0x422, 0x423, 0x416, 0x412,
    0x42c, 0x42b, 0x417, 0x428, 0x42d, 0x429, 0x427, 0x42a },
};
#endif /* _MB_EXTENDED_CHARSETS_WINDOWS */

#if defined(_MB_EXTENDED_CHARSETS_ISO) || defined(_MB_EXTENDED_CHARSETS_WINDOWS)
/* Handle one to five decimal digits.  Return -1 in any other case. */
static int
__micro_atoi (const char *s)
{
  int ret = 0;

  if (!*s)
    return -1;
  while (*s)
    {
      if (*s < '0' || *s > '9' || ret >= 100000)
	return -1;
      ret = 10 * ret + (*s++ - '0');
    }
  return ret;
}
#endif

#ifdef _MB_EXTENDED_CHARSETS_ISO
int
__iso_8859_val_index (int val)
{
  if (val >= 2 && val <= 16)
    {
      val -= 2;
      if (val > 10)
	--val;
      return (int) val;
    }
  return -1;
}

int
__iso_8859_index (const char *charset_ext)
{
  return __iso_8859_val_index (__micro_atoi (charset_ext));
}
#endif /* _MB_EXTENDED_CHARSETS_ISO */

#ifdef _MB_EXTENDED_CHARSETS_WINDOWS
int
__cp_val_index (int val)
{
  int cp_idx;
  switch (val)
    {
    case 437:
      cp_idx = 0;
      break;
    case 720:
      cp_idx = 1;
      break;
    case 737:
      cp_idx = 2;
      break;
    case 775:
      cp_idx = 3;
      break;
    case 850:
      cp_idx = 4;
      break;
    case 852:
      cp_idx = 5;
      break;
    case 855:
      cp_idx = 6;
      break;
    case 857:
      cp_idx = 7;
      break;
    case 858:
      cp_idx = 8;
      break;
    case 862:
      cp_idx = 9;
      break;
    case 866:
      cp_idx = 10;
      break;
    case 874:
      cp_idx = 11;
      break;
    case 1125:
      cp_idx = 12;
      break;
    case 1250:
      cp_idx = 13;
      break;
    case 1251:
      cp_idx = 14;
      break;
    case 1252:
      cp_idx = 15;
      break;
    case 1253:
      cp_idx = 16;
      break;
    case 1254:
      cp_idx = 17;
      break;
    case 1255:
      cp_idx = 18;
      break;
    case 1256:
      cp_idx = 19;
      break;
    case 1257:
      cp_idx = 20;
      break;
    case 1258:
      cp_idx = 21;
      break;
    case 20866:
      cp_idx = 22;
      break;
    case 21866:
      cp_idx = 23;
      break;
    case 101:
      cp_idx = 24;
      break;
    case 102:
      cp_idx = 25;
      break;
    case 103:
      cp_idx = 26;
      break;
    default:
      cp_idx = -1;
      break;
    }
  return cp_idx;
}

int
__cp_index (const char *charset_ext)
{
  return __cp_val_index (__micro_atoi (charset_ext));
}

#endif /* _MB_EXTENDED_CHARSETS_WINDOWS */
#endif /* _MB_CAPABLE */
