# RooUnfoldGSOC


## Task 1
Correctly set up ROOT with all the environment variables. This can be achieved using ROOT's `thisroot.sh`. </br>

Check out code
```
git clone https://github.com/nahimilega/RooUnfoldGSOC.git
cd RooUnfoldGSOC
```
To execute the macro using ROOT interactive shell.
```
root -l RooUnfoldGSOC.cxx
```
![Output](docs/images/q1_root_interactive.png?raw=true )

Now, to compile the code under CMake against the installation of ROOT
```
mkdir build
cd build
cmake ..
make
./RooUnfoldGSOC
```
![Output](docs/images/task_1.png?raw=true )
## Task 2: Normalization
For the detailed mathamatical explanation of the procedure kindly refer [here](docs/GSoC_RooUnfold.pdf)
![Output](docs/images/task_2_output.png?raw=true )

## Task 3: Matrix Operation
Now to replace the loop with the matrix operation, we would be first converting theresponseandtruthfrom histograms to a ROOT TMatrix object.responsewould be a 4×4 matrixandtruthwould be a ROOT vector object with 4 rows.

![Output](docs/images/task3.png?raw=true )

For the detailed mathamatical explanation of the procedure kindly refer here


## Task 4: Developing CTests
To confirm the similarity of results reported by loop and that of matrix, I developed a `tester.cpp` to run the compiled file and compare the reported output.

To run ctest
```
mkdir build
cd build
cmake ..
make
ctest
```
![Output](docs/images/task4.png?raw=true )
</br>
</br>
</br>
For the detailed report kindly refer [here](docs/GSoC_RooUnfold.pdf)

### Disclamer 

This is my first time trying out C++ development, so some of the naming conventions might not be a standard approach.  </br>
I am fortunate to get industry level experience in python development and also did a couple of college and school projects using C/C++. However, I am really thrilled to start my C++ development journey. Hopefully, by this year, I would be well acquainted with the C++ development process, in fact, one of my todos this year :)