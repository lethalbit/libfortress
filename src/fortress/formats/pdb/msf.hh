// SPDX-License-Identifier: LGPL-3.0-or-later
/* pdb/msf.hh - MSF container machinery */
#pragma once
#if !defined(_LIBFORTRESS_PDB_MSF_HH_)

#include <cstdint>
#include <array>

#include <fortress/utility.hh>
#include <fortress/common.hh>
#include <fortress/config.hh>


namespace fortress::pdb::msf {
	namespace v2 {
		/*
			MSF container magic for v2.

			This should be equivalent to the string:

			"Microsoft C/C++ program database 2.00\r\n\x00\x1A\x4A\x47\x00\x00"

			Why Microsoft decided to use that abomination as a magic value is
			beyond me.
		*/
		static constexpr std::array<uint8_t, 0x2C> magic{
			0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66,
			0x74, 0x20, 0x43, 0x2F, 0x43, 0x2B, 0x2B, 0x20,
			0x70, 0x72, 0x6F, 0x67, 0x72, 0x61, 0x6D, 0x20,
			0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65,
			0x20, 0x32, 0x2E, 0x30, 0x30, 0x0D, 0x0A, 0x1A,
			0x4A, 0x47, 0x00, 0x00
		};

		struct superblock_t final {
		private:
			std::array<uint8_t, magic.size()> _magic;

		};
	}

	namespace v7 {
		/*
			MSF container magic for v7.

			This should be equivalent to the string:

			"Microsoft C/C++ MSF 7.00\r\n\x1A\x44\x53\x00\x00\x00"

			When they moved to v7 they didn't even bother to keep the magic the
			same damn length. Thanks, I hate it.

		*/
		static constexpr std::array<uint8_t, 0x20> magic{
			0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66,
			0x74, 0x20, 0x43, 0x2F, 0x43, 0x2B, 0x2B, 0x20,
			0x4D, 0x53, 0x46, 0x20, 0x37, 0x2E, 0x30, 0x30,
			0x0D, 0x0A, 0x1A, 0x44, 0x53, 0x00, 0x00, 0x00
		};
		struct superblock_t final {
		private:
			std::array<uint8_t, magic.size()> _magic;
			uint32_t _blk_size;

		};
	}
}

#endif /* _LIBFORTRESS_PDB_MSF_HH_ */
