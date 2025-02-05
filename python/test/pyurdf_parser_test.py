
# Copyright 2025 Wissem CHIHA

from pytinyurdf import pyurdf_parser

def main():

    parser = pyurdf_parser.URDFParser()
    
    urdf_file = "C:/Users/chiha/OneDrive/Documents/tinyurdf/examples/urdf/spot.urdf" 

    parser.parse(urdf_file)
    model = parser.get()
    print(model.getName())
    print(model.__str__())

if __name__ == "__main__":
    main()