from setuptools import setup

setup(
    name="tinyurdf",
    version="1.0",
    author="Wissem CHIHA",
    description= "A modern C++ library for parsing URDF model files with Python bindings",
    url="https://github.com/wissem01chiha/tinyurdf",
    packages=["pytinyurdf"],
    package_dir={"pytinyurdf": "build/python"},
    py_modules=["pytinyurdf", "pyurdf_parser"],
    package_data={
        "pytinyurdf": ["*.pyd"]  
    },
    include_package_data=True
)
