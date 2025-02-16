Ressources
=====
- [stl_reader-documentation](https://sreiter.github.io/stl_reader/stl__reader_8h.html)
- [pybind11-documentation](https://pybind11.readthedocs.io/en/stable/)
- [urdfdom-debian-package](https://docs.ros.org/en/diamondback/api/urdf/html/index.html)
- [urdf-ros-wiki](https://wiki.ros.org/urdf)
  
## Related Projects

- [urdf-vis](https://github.com/openrr/urdf-viz) 
- [urdf-importer](https://github.com/Unity-Technologies/URDF-Importer)
- [related-ressources](https://stevengong.co/notes/URDF)

How to install Ninja  

- **On Windows** (via Chocolatey):  
  ```bash
  choco install ninja
  ```
- **On linux**
  ```bash
  sudo apt-get install ninja-build
 ```

How to install VCPKG
----

Official Link: <https://vcpkg.io/en/index.html>

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat # windows
./vcpkg/bootstrap-vcpkg.sh # Unix
```

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

