# Niobio Cash

The Niobio Cash is the Brazilian national cryptocurrency, just like Bitcoin but more anonymous and privacy centric with opaque and more analysis resistant blockchain. It is people's electronic cash, not connected to government or officials.

##Installation
```bash
$ apt-get update
$ apt-get upgrade
$ apt-get install qtbase5-dev libssl-dev cmake git libboost1.58-all-dev build-essential g++
$ git clone https://github.com/cryptoluka/cryptoluka
$ cd cryptoluka/
$ cmake CMakeLists.txt
$ make install -j 2
$ cd cryptonote/
$ make install -j 2
```

## Binaries

You can download the binaries for Linux, MacOS, and Windows [HERE](https://github.com/niobio-cash/Downloads)

## Building Niobio 

### On *nix and OSX

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.58.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/
* Alternatively, it may be possible to install them using a package manager.

To build, go the the project folder - same level of src - and run:
```
mkdir build
cd build
cmake ..
make
```

The resulting executables can be found in `build/src`.

**Advanced options:**

* Parallel build: run `make -j<number of threads>` instead of `make`.
* Debug build: run `make build-debug`.
* Test suite: run `make test-release` to run tests in addition to building. Running `make test-debug` will do the same to the debug version.
* Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.

### On Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run theas commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```
