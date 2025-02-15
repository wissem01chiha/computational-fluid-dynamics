# Tutorials

At the moment, the available documentation does not provide extensive examples.

- Additional test scripts, which may be useful, can be found in the [test](/test/) folder.  
- Samples of model files can be found in the [urdf](examples/urdf/) directory. These files are mainly sourced from the [urdf_files_dataset](https://github.com/Daniella1/urdf_files_dataset).

The examples assume that all installation instructions have been followed and that the library is successfully installed.

#### Example 1: Parsing an URDF File

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // Create the parser
  URDFParser parser;  
  // Parse the file
  parser.parse("path/to/tinyurdf/examples/urdf/example.urdf");  
  // Get the model 
  std::shared_ptr<Model> model_ = parser.get(); 
  // Print the model info  
  std::cout << model_->toString();
  return 0;
}
```
This will print all model data to the standard output without any formatting or adjustments.

Alternatively, when -DBUILD_SCRIPTS is enabled, you can parse the files from the command line as shown below:

```bash
./urdf_parse --file path/to/your/urdf_model.urdf
```

#### Example 2: Get Multijoint Model Data

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // Construct the parser
  URDFParser parser; 
  // Call the parsing routine 
  parser.parse("path/to/file.urdf");
  // Get the model 
  std::shared_ptr<Model> model_ = parser.get();  
  // Get the model name 
  std::string name = model_->getName(); 
  // Get model joints
  std::vector<std::shared_ptr<Joint>> joints_ = model_->getJoints();
  // Get model links 
  std::vector<std::shared_ptr<Link>> links_ = model_->getLinks();
  // Check whether the model is empty 
  bool status = model_->empty();
  return 0;
}
```
#### Python Interface Example
Here is an example of the Python interface, which is similar to the C++ interface:

```python
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
```