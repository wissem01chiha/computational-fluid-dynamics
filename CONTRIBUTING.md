# Contribution Guide

Due to time constraints, I am unable to maintain this project constantly. However, the work is in progress, and any contributions are greatly appreciated.  
Please refer to the following guidelines for areas where help is needed:

#### General Guidelines

- Use the minimal header includes as possible.
- Follow file naming conventions `.h` for headers and `.cc` for implementations
- The `common/` folder should contain only interfaces or shared code.
- Try to be highly modular with a focus on polymorphism.
- Avoid using Boost libraries wherever possible.

## Notes

- The current version parses and renders model joints, links, and visual elements. Other elements like transmissions and sensors will be supported in future releases.
- Physical consistency verification (e.g., inertia values) is not activated by default.
- A scaling issue may occur during rendering due to element marker sizes.
- The `COLLADA` file format for links' visual or collision meshes is not yet supported. Only `STL` files, `STEP` will be handled, other `CAD` file format, will be added progressivlly
- Multi-model handling, model interactions, and world parsing are not yet supported.
- File paths should be absolute. Relative paths are not currently supported.

## Style

We generally follow the [Google Style Guide](https://google.github.io/styleguide/). Currently, there is no automated checking pipeline for this, but I will personally review the code. Contributions to add such a pipeline would be highly appreciated.

---

## Current Tasks

Here are some key tasks where contributions are needed:

- [ ] Complete the implementation of the [urdf-graphiz](scripts/src/urdf-to-graphiz.cc) interface.
- [ ] Complete the development of core modules:
  - [camera](include/tinyurdf/core/camera.h)
  - [camera_parser](include/tinyurdf/internal/camera_parser.h)
- [ ] Add support for transmission parsing.
- [ ] Enhance the [model](include/tinyurdf/model.h) to support graph construction for complex robots.  
  We can rely on:
  - `std::map` or `std::unordered_map` for a simple implementation.
  - Complete the implementation of [internal_graph](include/tinyurdf/detail/internal_graph.h) module
  - An external graph library like [CXXGraph](https://github.com/ZigRazor/CXXGraph) for advanced graph representation is allowed to use.

- [ ] Add [Collada](https://en.wikipedia.org/wiki/COLLADA) file support using the [collada-dom](https://github.com/rdiankov/collada-dom) library.
- [ ] Ensure each implementation is tested in the [test](test/) folder.
- [ ] Add graph computation functions (e.g., computing model roots, leaves, etc.).
- [ ] Implement utility functions for inertial, volume, and collision computations, such as:
  - Total mass
  - Center of inertia
  - Total volume of the model
  - Density, and more
  - Precomputed Forward Kinematics 
  - Bounding Volume Hierarchy (BVH) for fast collision detection
  
---

## Additional Features

These additional features would improve the library:

- [ ] Add a custom project logo.
- [ ] Create a pipeline to deploy the library upon each release to **vcpkg** package manager.
- [ ] Check/test the [docker](./Dockerfile) pipeline build status and create a custom workflow.

---

If you have any questions or need clarification, feel free to [email me](mailto:chihawissem08@gmail.com).

Thank you for contributing!
