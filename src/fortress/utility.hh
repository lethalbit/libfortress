// SPDX-License-Identifier: LGPL-3.0-or-later
/* utility.hh - Various bits of utility and helper code */
#pragma once
#if !defined(_LIBFORTRESS_UTILITY_HH_)
#define _LIBFORTRESS_UTILITY_HH_

#include <algorithm>
#include <string>
#include <utility>
#include <type_traits>
#include <vector>

#include <fortress/common.hh>

/* enum class bitmask support */
template<typename F>
struct EnableBitmask{
	static constexpr bool enabled = false;
};

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F>::type
operator|(F lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return static_cast<F>(
		static_cast<utype>(lh) | static_cast<utype>(rh)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F>::type
operator&(F lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return static_cast<F>(
		static_cast<utype>(lh) & static_cast<utype>(rh)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled, F>::type
operator~(F en) {
	typedef typename std::underlying_type<F>::type utype;
	return static_cast<F>(
		~static_cast<utype>(en)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F>::type
operator^(F lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return static_cast<F>(
		static_cast<utype>(lh) ^ static_cast<utype>(rh)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F&>::type
operator|=(F& lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return lh = static_cast<F>(
		static_cast<utype>(lh) | static_cast<utype>(rh)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F&>::type
operator&=(F& lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return lh = static_cast<F>(
		static_cast<utype>(lh) & static_cast<utype>(rh)
	);
}

template<typename F>
typename std::enable_if<EnableBitmask<F>::enabled,F&>::type
operator^=(F& lh, F rh) {
	typedef typename std::underlying_type<F>::type utype;
	return lh = static_cast<F>(
		static_cast<utype>(lh) ^ static_cast<utype>(rh)
	);
}

/* enum <-> string mapping */
template<class T>
struct enum_pair_t final {

	using value_type = T;
	T _value;
	const char* _name;

	void value(const T value) noexcept { _value = value; }
	T value() const noexcept { return _value; }

	void name(const char* name) noexcept { _name = name; }
	const char* name() const noexcept { return _name; }
};

template<class Map, class Val>
std::string enum_name(Map m, Val v) noexcept {
	auto pos = std::find_if(
		std::begin(m),
		std::end(m),
		[&v](const typename Map::value_type& t){
			return (t.value() == v);
		});
	return (pos != std::end(m)) ?
		pos->name() :
		"UNKNOWN";
}

template<class Map>
typename Map::value_type::value_type enum_value(Map m, const std::string& n) noexcept {
	auto pos = std::find_if(
		std::begin(m),
		std::end(m),
		[&n](const typename Map::value_type& t){
			return (t.name() == n);
		});

	return (pos != std::end(m)) ?
		pos->value() :
		static_cast<typename Map::value_type::value_type>(0);
}

/* Extract a collection of flags set in a field */
/* This is kind of expensive run-time wise, being at leas O(n+1) but *shrug* */
template<typename T, typename A>
std::enable_if_t<std::is_enum_v<T>, std::vector<T>>
extract_flags(T flags, A& enum_table) {
	std::vector<T> _found_flags;
	using ut = typename std::underlying_type_t<T>;
	for (auto flag : enum_table) {
		if((flags & flag.value()) == flag.value() && static_cast<ut>(flag.value()) != 0)
			_found_flags.emplace_back(flag.value());
	}

	if(_found_flags.size() == 0)
		_found_flags.emplace_back(T{});

	return _found_flags;
}

template<typename T, typename A>
std::enable_if_t<std::is_enum_v<T>, std::vector<enum_pair_t<T>>>
extract_flag_pairs(T flags, A& enum_table) {
	std::vector<enum_pair_t<T>> _found_flags;
	using ut = typename std::underlying_type_t<T>;
	for (auto flag : enum_table) {
		if((flags & flag.value()) == flag.value() && static_cast<ut>(flag.value()) != 0)
			_found_flags.emplace_back(flag);
	}

	if(_found_flags.size() == 0)
		_found_flags.emplace_back(enum_table[0]);

	return _found_flags;
}


namespace fortress::utility {
	LIBFORTRESS_CLS_API
	uint16_t bswap16(const uint16_t x) noexcept;

	LIBFORTRESS_CLS_API
	uint32_t bswap32(const uint32_t x) noexcept;

	LIBFORTRESS_CLS_API
	uint64_t bswap64(const uint64_t x) noexcept;
}

#endif /* _LIBFORTRESS_UTILITY_HH_ */
