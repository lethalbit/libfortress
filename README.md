# `libfortress` [![Build Status](https://travis-ci.org/lethalbit/libfortress.svg?branch=master)](https://travis-ci.org/lethalbit/libfortress) [![codecov](https://codecov.io/gh/lethalbit/libfortress/branch/master/graph/badge.svg)](https://codecov.io/gh/lethalbit/libfortress) 
`libfortress` is a C++ library designed to be able to parse and write debug information in various formats, including DWARF and STABS.

## Requirements
`libfortress` does not depend on any external libraries other than the system C++ runtime.

## Supported Formats and Versions
<table>
  <thead>
    <tr>
      <th>Format</th>
      <th>Version</th>
      <th>Status</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="5">DWARF</td>
      <td>1</td>
      <td>:x:</td>
      <td><a href="http://dwarfstd.org/doc/dwarf_1_1_0.pdf">http://dwarfstd.org/doc/dwarf_1_1_0.pdf</a></td>
    </tr>
    <tr>
      <td>2</td>
      <td>:x:</td>
      <td><a href="http://dwarfstd.org/doc/dwarf-2.0.0.pdf">http://dwarfstd.org/doc/dwarf-2.0.0.pdf</a></td>
    </tr>
    <tr>
      <td>3</td>
      <td>:x:</td>
      <td><a href="http://dwarfstd.org/doc/Dwarf3.pdf">http://dwarfstd.org/doc/Dwarf3.pdf</a></td>
    </tr>
    <tr>
      <td>4</td>
      <td>:x:</td>
      <td><a href="http://dwarfstd.org/doc/DWARF4.pdf">http://dwarfstd.org/doc/DWARF4.pdf</a></td>
    </tr>
    <tr>
      <td>5</td>
      <td>:x:</td>
      <td><a href="http://dwarfstd.org/doc/DWARF5.pdf">http://dwarfstd.org/doc/DWARF5.pdf</a></td>
    </tr>
    <tr>
      <td>STABS</td>
      <td>N/A</td>
      <td>:x:</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan="2">PDB</td>
      <td>2</td>
      <td>:x:</td>
      <td></td>
    </tr>
    <tr>
      <td>7</td>
      <td>:x:</td>
      <td></td>
    </tr>
  </tbody>
</table>

## Building
To build `libfortress` you need the following:
 
 * ninja
 * meson >= 0.52.0
 * GCC >= 9.0.0

If you wish to build the Python bindings, you will also need the Python 3.8 libraries and headers as well.

To build the library, just do so like any other meson based project:

```
$ mkdir build && cd !$
$ meson .. -Dbuildtype=release
$ ninja && sudo ninja install
```
That will build `libfortress` with DWARF v4 and v5 support and support for STABS, as a shared library. It will also build the Python bindings.

If you wish to change the defaults, see `meson configure` for a comprehensive list of available options.

## License
libfortress is licensed under the LGPL, the full license is available in the [LICENSE](LICENSE) file.
