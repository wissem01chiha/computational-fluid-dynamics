from setuptools import setup

setup(
    name="pytinyurdf",
    version="1.0",
    author="Wissem CHIHA",
    description= "Python bindings for TinyURDF",
    url="https://github.com/wissem01chiha/tinyurdf",
    packages=["pytinyurdf"],
    package_dir={"pytinyurdf": "build/python"},
    py_modules=["pytinyurdf", "pyurdf_parser", "pyurdf_render"],
    package_data={
        "pytinyurdf": ["*.pyd"]  
    },
    include_package_data=True
)
