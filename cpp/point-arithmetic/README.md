# point-arithmetic (1/5)
### Goal
Once the program is fixed, `tests.cpp` should use the Point class to do simple Point arithmetic (not point**er** arithmetic). It should pass all 13 unit tests in `tests.cpp`. All the Point calculations are as one might expect. Adding two points adds their X coordinates together and their Y coordinates together. Subtracting two points takes the difference between the first and the second. Multiplying by a scalar or dividing by a divisor updates both coordinates in the Point accordingly. Two Points are equal when their X coordinates are equal and their Y coordinates are equal. Look at the included tests to see what the calculations (`tests.cpp`) and goal output (`goal.txt`) should look like.
### Compiling and Running
Use the following command to build the program:\
`clang++ -std=c++17 -o tests.out tests.cpp point.cpp`\
Then use this command to run the tests:\
`./tests.out`\
The results will appear in the console.