TUTORIELS
======

## Examples  
 

The available documentation does not provide extensive examples. 
- Demo example scripts are implemented in the [examples](/examples/src/) folder.  
- Additional test scripts, which may be useful, can be found in the [test](/test/) folder.  
- samples of models files can be found in the [urdf](examples/urdf/) directory, these files are mainly get from [urdf_files_dataset](https://github.com/Daniella1/urdf_files_dataset).

The examples assume that all installation instructions are followed, and the library is successfully installed.  

#### Example 1: parsing an urdf file  <!-- omit from toc -->

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // create the  parser
  URDFParser parser;  
  // parse the file
  parser.parse("path/to/tinyurdf/examples/urdf/example.urdf");  
  // get the model 
  std::shared_ptr<Model> model_ = parser.get(); 
  // print the model info  
  model_->print(std::cout);
  return 0;
}
```
This will print all model data to the standard output without any formatting or adjustments.

Alternatively, when `-DBUILD_SCRIPTS` is enabled, we can parse the files from the command line as shown below:

```bash
./parse --file path/to/your/urdf_model.urdf
```

#### Example 2: get a multijoint model data <!-- omit from toc -->

```cpp
#include "tinyurdf/tinyurdf.h"  

int main() {
  // construct the parser 
  URDFParser parser; 
  // call parsing routine 
  parser.parse("path/to/tinyurdf/examples/urdf/example.urdf");
  /// get the model 
  std::shared_ptr<Model> model_ = parser.get();  
  /// get the model name 
  std::string name = model_->getName(); 
  // get model joints
  std::vector<std::shared_ptr<Joint>> joints_ = model_->getJoints();
  // get model links 
  std::vector<std::shared_ptr<Link>> links_ = model_->getLinks();
  // check whether the model is empty 
  bool status = model_->empty();
  return 0;
}
```
#### Example 4: rendering a multijoint model <!-- omit from toc -->


```cpp
#include "tinyurdf/tinyurdf.h"

int main() {
  // create the parser
  URDFParser parser;
  const char* file_path = "path/to/tinyurdf/examples/urdf/example.urdf";
  // parse the file
  parser.parse(file_path);
  // create the renderer
  URDFRenderer render;
  // set the model for rendering
  render.setModel(*(parser.get())); 
  // set background color
  render.setBackground(0.9, 0.9, 0.9, 1.0);  
  // disable label text
  render.setLabelText(false);
  // show the rendered model                
  render.show();                              
  return 0;
}
```

alternatively, we can render the model with customization options using the built render script:
```bash
./render --file path/to/your/urdf_model.urdf --red 0.5 --green 0.5 --blue 0.7 --labels true
```