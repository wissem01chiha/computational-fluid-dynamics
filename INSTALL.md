Installation
=======

##  Prerequisites

1. C++17 compatible compiler (GCC 7.1+, Clang 5.0+, MSVC 2017+)
2. CMake (version 3.14+)
## Dependencies

TinyURDF currently depends on the following libraries:
- [TinyXML2](https://github.com/leethomason/tinyxml2)
- [loguru](https://github.com/emilk/loguru)
- [Eigen3](https://eigen.tuxfamily.org)
- [cxxopts](https://github.com/jarro2783/cxxopts)

These dependencies are automatically fetched and compiled during the build process no sperate build process is required
The library has been successfully built and tested on the following platforms with the corresponding dependencies:

#### Windows 
1. Compiler: MSVC 2017, CMake: 3.22.1
#### Linux 
1. Compiler: GCC 8, CMake: Latest

Other platforms or compilers have not yet been tested. Please open an issue on [GitHub Issues](https://github.com/wissem01chiha/tinyurdf/issues) for any suspected bugs,

we recommend using **Ninja** with Microsoft Visual Studio for faster builds, for more details go to
[Ninja-Installtion](docs/Ressources.md)

 
#### Build

run the following commands to build the project:

```bash
mkdir build && cd build
cmake -G Ninja  ..
ninja
ninja install 
```
By default, this will use the MSVC compiler on Windows and the default CMake options. To use a different compiler with Ninja, run:

```bash
cmake -G Ninja -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..
make 
make install 
```
#### for Unix-based Systems or MinGW on Windows 
If you prefer not to use Ninja, you can build the project using Unix Makefiles:  
```bash
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
make install 
```
These commands will build and install the static/shared library under the `lib/` directory and the include files in the `include/` directory of the build folder.  

#### Build Configuration Options
You can customize the build using the following CMake options:
```bash
cmake -G Ninja \
      -DBUILD_TESTS=FALSE \       # Build tests 
      -DBUILD_PYTHON3=FALSE \     # Enable Python 3 bindings
      -DBUILD_SCRIPTS=TRUE \      # Build cpp scripts 
      -DBUILD_DOCS=FALSE          # Build documentation with Doxygen  
      -DBUILD_SHARED_LIBS = FALSE # build shared librarry 

```
 For Python bindings build and installation, enable the `-DBUILD_PYTHON3` flag, and run the following command from the root of the project to installthem locally

> ```bash  
> pip install --user .  
> ```  
> Note that Python bindings are not currently tested, many bugs exist. Use them at your own risk, or feel free to contribute
TinyURDF will soon be available for installation via **vcpkg**.  





