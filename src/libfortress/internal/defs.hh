// SPDX-License-Identifier: BSD-3-Clause
#pragma once
#if !defined(libfortress_internal_defs_hh)
#define libfortress_internal_defs_hh

#if defined(_MSC_VER) && !defined(_WINDOWS)
#	define _WINDOWS 1
#endif

#ifdef _WINDOWS
#	ifdef LIBFORTRESS_BUILD_INTERNAL
		// NOLINTNEXTLINE
#		define LIBFORTRESS_CLS_API __declspec(dllexport)
#	else
		// NOLINTNEXTLINE
#		define LIBFORTRESS_CLS_API __declspec(dllimport)
#	endif
	// NOLINTNEXTLINE
#	define LIBFORTRESS_API extern LIBFORTRESS_CLS_API
	// NOLINTNEXTLINE
#	define LIBFORTRESS_CLS_MAYBE_API
#else
	// NOLINTNEXTLINE
#	define LIBFORTRESS_CLS_API __attribute__ ((visibility("default")))
	// NOLINTNEXTLINE
#	define LIBFORTRESS_CLS_MAYBE_API LIBFORTRESS_CLS_API
	// NOLINTNEXTLINE
#	define LIBFORTRESS_API extern LIBFORTRESS_CLS_API
#endif

#endif /* libfortress_internal_defs_hh */
