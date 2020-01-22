SQLiteC++
---------

[![release](https://img.shields.io/github/release/SRombauts/SQLiteCpp.svg)](https://github.com/SRombauts/SQLiteCpp/releases)
[![license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/SRombauts/SQLiteCpp/blob/master/LICENSE.txt)
[![GitHub Actions Build status](https://github.com/SRombauts/SQLiteCpp_Example/workflows/build/badge.svg)](https://github.com/SRombauts/SQLiteCpp_Example/actions "GitHhub Actions Build status")

[SQLiteC++ (SQLiteCpp)](https://github.com/SRombauts/SQLiteCpp) is a smart and easy to use C++ SQLite3 wrapper.

[See SQLiteC++ website on GitHub](http://srombauts.github.com/SQLiteCpp).

Keywords: sqlite, sqlite3, C, library, wrapper C++, simple example

## About SQLiteC++:

SQLiteC++ offers an encapsulation around the native C APIs of SQLite,
with a few intuitive and well documented C++ classes.

### License:

Copyright (c) 2012-2020 Sébastien Rombauts (sebastien.rombauts@gmail.com)
<a href="https://www.paypal.me/SRombauts" title="Pay Me a Beer! Donate with PayPal :)"><img src="https://www.paypalobjects.com/webstatic/paypalme/images/pp_logo_small.png" width="118"></a>

Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
or copy at http://opensource.org/licenses/MIT)

## Getting started
### Git:

Use git to clone the repository. Then init and update submodule "SQLiteCpp".

```Shell
git clone https://github.com/SRombauts/SQLiteCpp_Example.git
cd SQLiteCpp_Example
git submodule init
git submodule update
```

### CMake and build:

Use build.bat or ./build.sh script, or cmake command line (example for Linux): 

```Shell
mkdir -p build
cd build

# Generate a Makefile for GCC (or Clang, depanding on CC/CXX envvar)
cmake ..

# Build (ie 'make')
cmake --build .
```

On Windows, you can also open the Visual Studio Solution (in the build/ subdirectory).

### Run

Launch build/SQLiteCpp_Example(.exe) from the command line

## How to contribute
### GitHub website
The most efficient way to help and contribute to this wrapper project is to
use the tools provided by GitHub:
- please fill bug reports and feature requests here: https://github.com/SRombauts/SQLiteCpp/issues
- fork the repository, make some small changes and submit them with pull-request

