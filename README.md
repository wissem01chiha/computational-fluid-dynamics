# Airfoil 1.0
Welcome to "Airfoil 1.0 ", an open-source Fortran 95  standlone application aimed at developing new solutions for optimizing the shapes of aircraft wings.
My goal is to provide a simple, easy-to-use application for students and  engineers to perform complex aerodynamics optimisation analysis.
  
# Installation
To install the app, follow these steps:
 * Download the project executable files from the link below :
   https://drive.google.com/file/d/1iDMlaMpPCSBUW9uhPZHJR92B5l6HsUUA/view?usp=share_link 
 * Unzip  Airfoil.rar in an empty folder 
 * Run Airfoil.exe 
 * Calculation results will be generated in the current folder
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

gfortran Airfoil.f90 -o Airfoil_optimization
 

 

 

wissem.chiha@ept.ucar.tn 

chihawissem08@gmail.com

# License
This project is licensed under the GNU  License - see the LICENSE file for details.

# References 




 
