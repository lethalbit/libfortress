// SPDX-License-Identifier: LGPL-3.0-or-later
/* utility.cc - Various bits of utility and helper code */
#include <fortress/common.hh>
#include <fortress/utility.hh>
#include <fortress/config.hh>

namespace fortress::utility {
	/* Some basic byte swapping machinery */
	uint16_t bswap16(const uint16_t x) noexcept {
		return (((x & 0x00FFU) << 8U) |
		        ((x & 0xFF00U) >> 8U));
	}

	uint32_t bswap32(const uint32_t x) noexcept {
		return (((x & 0x000000FFU) << 24U) |
		        ((x & 0x0000FF00U) << 8U ) |
		        ((x & 0x00FF0000U) >> 8U ) |
		        ((x & 0xFF000000U) >> 24U));
	}

	uint64_t bswap64(const uint64_t x) noexcept {
		return (((x & 0x00000000000000FFU) << 56U) |
		        ((x & 0x000000000000FF00U) << 40U) |
		        ((x & 0x0000000000FF0000U) << 24U) |
		        ((x & 0x00000000FF000000U) << 8U ) |
		        ((x & 0x000000FF00000000U) >> 8U ) |
		        ((x & 0x0000FF0000000000U) >> 24U) |
		        ((x & 0x00FF000000000000U) >> 40U) |
		        ((x & 0xFF00000000000000U) >> 56U));
	}
}
