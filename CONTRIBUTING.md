# Contribution Guide
 
Due to time constraints, I am unable to maintain this project constantly. However, the work is in progress, and any contributions are greatly appreciated.  
Please refer to the following guidelines for areas where help is needed:

use the minimail header icnludes as possible:
floow the 
the common/ folder do  not provide implentation in src folder, for heder only intrafces/code shared 
internally use
Minimalist OpenGL renderer (no ROS)
Real-time joint manipulation (sliders, buttons,)
Precomputed Forward Kinematics (FK) Cache
 3. Bounding Volume Hierarchy (BVH) for Fast Collision Detection
 4. Step 2: Convert Data to NumPy (for ML Compatibility)
Store joint limits, link masses, inertia tensors, etc. in NumPy arrays.

📌 Step 3: Save as .npz, .pt, or .tf
These formats allow easy loading into PyTorch or TensorFlow.
## Notes

- the current version parses and renders model joints, links, and visual elements. Other elements like transmissions and sensors will be supported in future releases.
- physical consistency verification (e.g., inertia values) is not activated by default.
- a scaling issue may occur during rendering due to element marker sizes.
- The COLLADA file format for links' visual or collision meshes is not yet supported. Only STL files have been tested.
- multi-model handling, model interactions, and world parsing/visualization are not yet supported.
- File paths should be absolute. Relative paths are not currently supported.

designed to hihtly modular with focus on polymorhism 

## Style

we generally follow the [Google Style Guide](https://google.github.io/styleguide/), currently, there is no automated checking pipeline for this, but I will personally review the code. contributions to add such a pipeline would be highly appreciated.

---

## Current Tasks

Here are some key tasks where contributions are needed:
- [ ] complte the implentaion of the [urdf-graphiz](scripts/src/urdf-to-graphiz.cc) inetrafce 
- [ ] Complete the development of core modules:
  - [camera](include/tinyurdf/core/camera.h)
  - [camera_parser](include/tinyurdf/inetrnal/camera_parser.h)
- [ ] Add support for transmission parsing. 
- [ ] Enhance the [model](include/tinyurdf/model.h) to support graph construction for complex robots.  
  We can rely on:
  - `std::map` or `std::unordered_map` for a simple implementation
  - An external graph library like [CXXGraph](https://github.com/ZigRazor/CXXGraph) for advanced graph representation
- [ ] Avoid using Boost libraries wherever possible.
- [ ] Add support for rendering collision shapes of links with lighter colors or textures.
- [ ] Add support for link color display.
- [ ] Add support for material display and/or texture file parsing and rendering.
- [ ] Add [Collada](https://en.wikipedia.org/wiki/COLLADA) file support using the [collada-dom](https://github.com/rdiankov/collada-dom) library.
- [ ] Ensure each implementation is tested in the [test](test/) folder.
- [ ] Add graph computation functions (e.g., computing model roots, leaves, etc.).
- [ ] Implement utility functions for inertial, volume, and collision computations, such as:
  - Total mass
  - Center of inertia
  - Total volume of the model
  - Density, and more
---

## Additional Features

These additional features would improve the library:

- [ ] Add a custom project logo.
- [ ] Create a pipeline to deploy the library upon each release to **vcpkg** and **Conan Center** package managers. 
- [ ] check/test the [docker](./Dockerfile) pipline build status and create a custom workflow.
  
---

If you have any questions or need clarification, feel free to [email me](mailto:chihawissem08@gmail.com).

Thank you for contributing!

