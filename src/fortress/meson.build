pkg = import('pkgconfig')

fortress_srcs = [
	'utility.cc'
]

fortress_headers = [
	'common.hh',
	'utility.hh',
]


subdir('formats')

cfg_header = configure_file(
	configuration: config,
	input: 'config.hh.in',
	output: 'config.hh'
)

install_headers(cfg_header, subdir: 'fortress')

libfortress = library(
	'fortress',
    fortress_srcs,
    include_directories: [
    	include_directories('..'),
    ],
    install: true
)

pkg.generate(
	name: 'fortress',
	description: 'A C++ library designed to be able to parse and write debug information in various formats, including DWARF and STABS.',
	url: 'https://github.com/lethalbit/fortress',
	version: meson.project_version(),
	filebase: 'libfortress',
	libraries: [ libfortress ],
	subdirs: [ '.' ]
)

install_headers(fortress_headers, subdir: 'fortress')
