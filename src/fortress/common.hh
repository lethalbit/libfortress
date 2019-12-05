// SPDX-License-Identifier: LGPL-3.0-or-later
/* common.hh - Common macros and the like for libfortress */
#pragma once
#if !defined(_LIBFOTRESS_COMMON_HH_)
#define _LIBFOTRESS_COMMON_HH_

#if __GNUC__ >= 9
	#define LIBFORTRESS_VIS	__attribute__ ((visibility("default")))
#else
	#error "libfortress requires GCC version 9 or greater"
#endif
#define LIBFORTRESS_CLS_API LIBFORTRESS_VIS
#define LIBFORTRESS_API extern LIBFORTRESS_CLS_API
#define LIBFORTRESS_DEPRECATE(reason, type) [[deprecated(reason)]] LIBFORTRESS_API type

#endif /* _LIBFOTRESS_COMMON_HH_ */
