doxygen = find_program('doxygen', required: false)
if doxygen.found()
	dot = find_program('dot', required: false)
	doxydat   = configuration_data()
	doxydat.set('VERSION', '@0@ @1@'.format(meson.project_version(), git_hash))
	# If we have dot, we will generate class diagrams
	if dot.found()
		doxydat.set('USE_DOT', 'YES')
	else
		doxydat.set('USE_DOT', 'NO')
	endif

	fmt_cfg_base = '../src/fortress/formats/@0@/ '
	fmt_incs = ''
	foreach fmt : get_option('formats')
		fmt_incs = ' '.join([fmt_cfg_base.format(fmt), fmt_incs])
	endforeach

	doxydat.set('FMT_INC', fmt_incs)

	doxyfile = configure_file(
		input: 'Doxyfile.in',
		output: 'Doxyfile',
		configuration: doxydat,
		install: false
	)

	custom_target(
		'doc',
		input: doxyfile,
		output: [ 'html', 'latex' ],
		command: [ doxygen, doxyfile ],
		install: false,
		build_by_default: true
	)
else
	warning('Can not find Doxygen, not generating documentation as requested')
endif
