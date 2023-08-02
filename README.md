# Nomoto_model

This is 1st order Nomoto model in C++. The model is used for tuning autopilot systems for ships.
The program may also serve as a template for ship models with a higher degree of freedom, e.g. 3DoF.

The model is integrated within a search-based planning library (SBPL).
This combination of the Nomoto model and SBPL is used for the creation of motion primitives with the A* algorithm for finding the optimal paths for autonomous ships. 



For simulating the Nomoto model ODEint was used which is included in the boost library.
integrate_adaptive is used if the observer is called at each timestep. Syntax:
integrate_adaptive(stepper , system , x0 , t0 , t1 , dt , observer)


# Cmake is used to create the build files.

Clone the code from https://github.com/sumit280188/Nomoto_model.git
Create a build directory in the new git directory
```
cd /home/$USER/Nomoto_model 
mkdir -p build 

Create the build files with cmake and build the code
cmake -DCMAKE_BUILD_TYPE=Releases -S . -B build && cmake --build build


#  Running the code
goto cd /home/$USER/Nomoto_model
goto cd build
./main 
