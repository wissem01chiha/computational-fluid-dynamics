# Airfoil 1.0
 Welcome to "Airfoil 1.0," an open-source Fortran 95 standalone application aimed at developing new solutions for optimizing the shapes of aircraft wings.
 My goal is to provide a simple and easy-to-use application for students and engineers to perform complex aerodynamic optimization analysis.
  
# Installation
 To install the application, please follow these steps:

* Click on the link below to download the project executable files:
*  https://drive.google.com/file/d/1iDMlaMpPCSBUW9uhPZHJR92B5l6HsUUA/view?usp=share_link 
* Save the downloaded files to a directory of your choice.
 * Extract "Airfoil.rar" in an empty folder 
 * Run Airfoil.exe 
 * The calculation results for "Airfoil 1.0" will be generated in the current working directory. 
 * Please ensure that you have write permissions in the current working directory before running the application. !
 * Enjoy !
 
 
 # Usage 
To use the application follow these steps:
  * Enter the airfoil shape parameters (chord length, camber,...) 
  * Enter the flow conditions  (fuild density ,airspeed,...)
  * Enter the solver parameters ( nodes number , interpolation error ,...)
  * The app will generate a ".txt" file for the analysis report 
  * Calculations data are generated in ".csv" files for each variable (pressure, velocity,...)
  
# Development Contributions
The acutal version perform only static calculations.The project is still under development to integrate  new innovative optimisation tools as well as turbulence modeling.Contributions to this project are welcome
  ## Prerequisites
To compile the source code below I recommand the fortran compiler GNU Fortran (GFortran) and Visual Studio code with Modern Fortran extension  
 ## Run commands 
 * To run Airfoil 1.0, you can use the following command in the terminal or command prompt: " ./Airfoil"
 
 This will execute the Airfoil 1.0 executable file in the current working directory 
 
 * To compile the Airfoil 1.0 Fortran source code using the gfortran compiler, you can use the following command : gfortran Airfoil.f95 -o Airfoil

 * To generate a standalone executable file for Airfoil 1.0 using the gfortran compiler, you can use the following command : gfortran -static Airfoil.f95 -o Airfoil

           
# License
This project is licensed under the GNU  License - see the LICENSE file for details.

# References 
 I do like CFD VOL 1: Katate Masatsuka : 2009
 
 http://ossanworld.com/cfdbooks/cfdcodes.html
 # feedback 
If you have any feedback or suggestions for improvement, please don't hesitate to let me know.
 
chihawissem08@gmail.com

 
