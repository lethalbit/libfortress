// SPDX-License-Identifier: BSD-3-Clause

#include <libfortress/config.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(libfortress, m) {

	m.doc() = "A library for parsing and generating various debug file formats.";
	m.attr("__version__") = Fortress::Config::version;

}
