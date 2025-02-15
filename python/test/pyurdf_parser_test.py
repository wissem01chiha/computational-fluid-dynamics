# This file is a part of TinyURDF
# Copyright 2024-2025 Wissem CHIHA
#
# Description:
#   This script tests the TinyURDF Python bindings by parsing a URDF file.
#   It loads a URDF model, retrieves its name, and prints its string representation.
#
# Usage:
#   Simply run the script to parse a predefined URDF file.
#
# Requirements:
#   - pytinyurdf (TinyURDF Python bindings)

from pytinyurdf import pyurdf_parser

def main():
    
    parser = pyurdf_parser.URDFParser()
    urdf_file = "spot.urdf"
    parser.parse(urdf_file)
    model = parser.get()
    print(model.getName())
    print(model.__str__())

if __name__ == "__main__":
    main()