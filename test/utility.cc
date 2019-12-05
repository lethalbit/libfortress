#include <fortress/utility.hh>
#include <fortress/common.hh>
#include <fortress/config.hh>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cstdio>
#include <type_traits>
#include <algorithm>
#include <string>
#include <vector>

TEST_CASE( "Byte Swapping" , "[utility]") {
	REQUIRE(fortress::utility::bswap16(0xEDF3U) == 0xF3EDU);
	REQUIRE(fortress::utility::bswap32(0x7B04D1BU) == 0x1B4DB007U);
	REQUIRE(fortress::utility::bswap64(0x7F62B769CDF8AE44U) == 0x44AEF8CD69B7627FU);
}

enum class Flags : uint8_t {
	None   = 0,
	Foo    = 1 << 1,
	Bar    = 1 << 2,
	Baz    = 1 << 3,
	Qux    = 1 << 4,
	Quux   = 1 << 5,
	Corge  = 1 << 6,
	Grault = 1 << 7,
};

template<>
struct EnableBitmask<Flags>{
		static constexpr bool enabled = true;
};
const std::array<const enum_pair_t<Flags>, 8> flags_s{{
	{ Flags::None,    "No Flags" },
	{ Flags::Foo,     "Foo"      },
	{ Flags::Bar,     "Bar"      },
	{ Flags::Baz,     "Baz"      },
	{ Flags::Qux,     "Qux"      },
	{ Flags::Quux,    "Quux"     },
	{ Flags::Corge,   "Corge"    },
	{ Flags::Grault,  "Grault"   },
}};

TEST_CASE( "Flag extraction", "[utility]" ) {
	/* This test isn't the best as it's order-dependent for the flags */
	SECTION( "Raw flag extraction" ) {
		Flags tc1 = Flags::Foo | Flags::Baz | Flags::Grault;
		std::vector<Flags> tc1_exp = { Flags::Foo , Flags::Baz , Flags::Grault };

		auto retvec = extract_flags<Flags>(tc1, flags_s);

		REQUIRE(retvec.size() == tc1_exp.size());
		REQUIRE(retvec == tc1_exp);
	}

	SECTION( "Flag pair extraction" ) {
		Flags tc2 = Flags::Grault | Flags::Quux | Flags::Baz | Flags::Bar;
		std::vector<enum_pair_t<Flags>> tc2_exp = {
			{ Flags::Grault,  "Grault"   },
			{ Flags::Quux,    "Quux"     },
			{ Flags::Baz,     "Baz"      },
			{ Flags::Bar,     "Bar"      },
		};

		auto retvec = extract_flag_pairs<Flags>(tc2, flags_s);

		/*
			We need to reverse the returned vector because it's in-order
			while the test vector is inverted.
		*/
		std::reverse(retvec.begin(), retvec.end());

		REQUIRE(retvec.size() == tc2_exp.size());
		REQUIRE(std::equal(retvec.begin(),
					retvec.end(),
					tc2_exp.begin(),
					[](const enum_pair_t<Flags>& l, const enum_pair_t<Flags>& r){
						return (l.value() == r.value());
					}));
	}

	SECTION ( "Unknown Flag extraction" ) {
		auto ret = extract_flags<Flags>(Flags::None, flags_s);
		auto ret2 = extract_flag_pairs<Flags>(Flags::None, flags_s);

		REQUIRE(ret.size() == 1);
		REQUIRE(ret2.size() == 1);

		REQUIRE(ret[0] == Flags::None);

		REQUIRE(ret2[0].value() == Flags::None);
		REQUIRE(std::string{ret2[0].name()} == std::string{"No Flags"});
	}
}
