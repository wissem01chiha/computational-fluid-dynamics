
# Copyright 2025 Wissem CHIHA

from pytinyurdf import  pyurdf_render

def main():

    parser = pyurdf_parser.URDFParser()
    
    urdf_file = "C:/Users/chiha/OneDrive/Documents/tinyurdf/python/test/simple_test.urdf" 

    parser.parse(urdf_file)
    model = parser.get()
    parser.print()

if __name__ == "__main__":
    main()