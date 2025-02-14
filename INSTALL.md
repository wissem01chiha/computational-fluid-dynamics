Installation
=======

The library has been successfully built and tested on the following platforms with the corresponding dependencies:

#### Windows <!-- omit from toc -->
1. Compiler: MSVC 2017, CMake: 3.22.1
#### Linux <!-- omit from toc -->
1. Compiler: GCC 8, CMake: Latest

Other platforms or compilers have not yet been tested. Please open an issue on [GitHub Issues](https://github.com/wissem01chiha/tinyurdf/issues) for any suspected bugs,
we recommend using **Ninja** with Microsoft Visual Studio for faster builds.  

Install Ninja  

- **On Windows** (via Chocolatey):  
  ```bash
  choco install ninja
  ```
- **On linux**
  ```bash
  sudo apt-get install ninja-build
  ```
#### Building the Project <!-- omit from toc -->

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
#### for Unix-based Systems or MinGW on Windows <!-- omit from toc -->
If you prefer not to use Ninja, you can build the project using Unix Makefiles:  
```bash
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
make install 
```
These commands will build and install the static/shared library under the `lib/` directory and the include files in the `include/` directory of the build folder.  

> [!NOTE]  
> This build method is typically slower than the Ninja-based build.
#### Build Configuration Options <!-- omit from toc -->
You can customize the build using the following CMake options:
```bash
cmake -G Ninja \
      -DBUILD_TESTS=FALSE \       # Build tests 
      -DBUILD_PYTHON3=FALSE \     # Enable Python 3 bindings
      -DUSE_VTK=TRUE \            # Use VTK as the default renderer 
      -DBUILD_SCRIPTS=TRUE \      # Build cpp scripts 
      -DBUILD_DOCS=FALSE          # Build documentation with Doxygen  
      -DBUILD_SHARED_LIBS = FALSE # build shared librarry 

```
> [!NOTE]  
> For Python bindings build and installation, enable the `-DBUILD_PYTHON3` flag, and run the following command from the root of the project:  
> ```bash  
> pip install --user .  
> ```  
> Note that Python bindings are not currently tested, many bugs exist. Use them at your own risk, or feel free to contribute

TinyURDF will soon be available for installation via **vcpkg**, **Conan**, and **CMake FetchContent**.  





How to install VCPKG
----

Official Link: <https://vcpkg.io/en/index.html>

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat # windows
./vcpkg/bootstrap-vcpkg.sh # Unix
```

How to install the Conan Package Manager
----

Official installation guide is [here](https://docs.conan.io/2/).

The conan database is [here](https://conan.io/center/).

How to install Google Test on ubuntu
----

for gtest installation : https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5?permalink_comment_id=2822039#gistcomment-2822039

```cmd
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp lib/libgtest* /usr/lib/
cd ..
sudo rm -rf build
```
Then do:
```cmd
sudo mkdir /usr/local/lib/googletest
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a
```

### Installation Steps

1. Install Python (3.7+)
2. Type ``pip install --user -U conan`` into the terminal
   1. Unix: Append conan to the PATH by: ``source ~/.profile``
3. Run the conan command: ``conan``
4. conan profile detect --force
5. conan profile path default

## Formatter and Static Analyzer

### Tooling

Clang-Format: Formatting tool for your C/C++ code:

- Documentation for Clang-Format: [Link](https://clang.llvm.org/docs/ClangFormat.html)

Clang-Tidy: Static linting tool for your C/C++ code:

- Documentation for Clang-Tidy: [Link](https://clang.llvm.org/extra/clang-tidy/)

Cmake-Format:

```bash
pip install cmake-format # python 3.7+
```

### Coverage Tools

```bash
sudo apt-get install gcovr
pip install -U gcovr
```

### Install Clang Tools

It's included in the LLVM toolchain, but also installable by apt, brew, winget etc.

https://github.com/llvm/llvm-project/releases/tag/llvmorg-16.0.0


