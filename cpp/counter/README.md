# counter 
### Goal
Once fixed, `counter.cpp` should read a text file and count the number of each data type in the file. Each line in an input file will have a one-letter code followed by a space indicating what data type is on that line (b = boolean, i = integer, d = double, s = string). After the space, data of that type will be read and counted by a counter class. The number of each data type will be printed to the console at the end. Look at the included examples to see what the input (`test<N>.txt`) and goal output (`goal<N>.txt`) look like.
### Compiling and Running
Use the following command to build the program:\
`clang++ -std=c++17 -o counter.out counter.cpp`\
Then use this command to run the code on `<TEST_NAME>.txt`:\
`./counter.out <TEST_NAME>.txt`\
The results will appear in the console.