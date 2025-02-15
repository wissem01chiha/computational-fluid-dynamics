Changelog
======

#### CHANGES (10-02-2025)
- Removed the 3D visualization engine.
- Updated Doxygen layout documentation.
- Refactored the `include/` and `src/` folders for modularity.
- Planned to use OpenMP for parallel parsing.
- Remove the dependancy on c++ iostreams, **print(std::cout)** replaced by **toString()** function,
  for better language bindings
- Removed **Conan** integration; will support only **vcpkg**.

#### CHANGES (24-01-2025)
- Removed the example scripts, as they already exist in `README.md`.  
  The `examples` folder will now only contain samples of files, meshes, or related configurations.
- Updated the `README.md` file with the latest changes.
- Added a scripting engine written in C++, located in the `script/` folder.
- Built the Conan recipe for dependency management.
- Compressed the `meshes` folder into a `.rar` archive to improve download speed.
- Updated Doxygen configuration files for documentation generation.
- Removed unnecessary lines from `.gitignore`.

#### CHANGES (01-11-2024)
- First experimental version.

