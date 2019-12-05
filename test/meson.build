test_harness_srcs = [
	'dwarf_v1.cc',
	'dwarf_v2.cc',
	'dwarf_v3.cc',
	'dwarf_v4.cc',
	'dwarf_v5.cc',

	'stabs.cc',
	'pdb.cc',

	'leb128.cc',
	'utility.cc',
]


test_harness = executable(
	'libfortress-test',
	test_harness_srcs,
	link_with: libfortress,
	include_directories: [
		include_directories('../src', '../third_party/catch2/single_include/'),
    ],
	install: false,
)

test('libfortress_test_harness', test_harness)
