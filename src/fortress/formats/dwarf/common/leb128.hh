// SPDX-License-Identifier: LGPL-3.0-or-later
/* dwarf/common/leb128.hh - Little-endian base 128 encoder / decoder machinery */
#pragma once
#if !defined(_LIBFORTRESS_LEB128_HH_)
#define _LIBFORTRESS_LEB128_HH_

#include <type_traits>
#include <cstdint>
#include <vector>

namespace fortress::utility {
	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, std::vector<uint8_t>>
		leb128_encode(T num) {
		std::vector<uint8_t> enc{};
		bool cont{true};
		uint8_t byte{};
		while(cont) {
			byte = (num & 0x7F);
			num >>= 7;
			if((num == 0 && (byte & 0x40)) || (num == -1 && !!(byte & 0x40)))
				cont = false;
			else
				byte |= 0x80;
			enc.emplace_back(byte);
		}
		return enc;
	}

	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, T>
		leb128_decode(std::vector<uint8_t>& vec) {
		T enc{};
	    uint64_t shift{};
	    for(auto& byte : vec) {
	        enc |= (byte & 0x7F) << shift;
	        shift += 7;
	    }
    	return enc;
	}

	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>, std::vector<uint8_t>>
		leb128_encode(T num) {
		std::vector<uint8_t> enc{};
		uint8_t byte{};
		do {
			byte = (num & 0x7F);
			if((num >>= 7) != 0)
				byte |= 0x80;
			enc.emplace_back(byte);
		} while(num != 0);
		return enc;
	}

	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>, T>
		leb128_decode(std::vector<uint8_t>& vec) {
		T enc{};
		uint64_t shift{};
		for(auto& byte : vec) {
			enc |= (byte & 0x7F) << shift;
			shift += 7;
		}
		return enc;
	}
}

#endif /* _LIBFORTRESS_LEB128_HH_ */
