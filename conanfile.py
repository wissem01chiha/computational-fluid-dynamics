from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps

class CompressorRecipe(ConanFile):
    name = "tinyurdf"
    version = "1.0.0"
    
    license = "MIT License"
    author = "Wissem CHIHIA  chihawissem08@gmail.com"
    url = "https://github.com/wissem01chiha/tinyurdf"
    description = "A Modern C++ Library for Parsing and Visualizing URDF Model Files"
    
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "cmake/*", "extern/*", "include/*", "src/*", "CMakeLists.txt", "test/*", "examples/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["hello"]
