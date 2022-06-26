// SPDX-License-Identifier: BSD-3-Clause

#include <libfortress/config.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(libfortress, m) {

	m.doc() = "A library for parsing and generating various debug file formats.";
	m.attr("__version__") = Fortress::Config::version;

	[[maybe_unused]]
	auto dwarf = m.def_submodule("dwarf", "Fortress module for parsing and generating DWARF debug info");
	[[maybe_unused]]
	auto pdb = m.def_submodule("pdb", "Fortress module for parsing and generating PDB debug info");
	[[maybe_unused]]
	auto stabs = m.def_submodule("stabs", "Fortress module for parsing and generating STABS debug info");
	[[maybe_unused]]
	auto vms = m.def_submodule("vms", "Fortress module for parsing and generating VMS debug info");

}
