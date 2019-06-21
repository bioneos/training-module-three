# sorting-strings (2/5)
### Goal
Once fixed, `SortingStrings.java` should read a text file and reorder all the space-separated (or line-separated) strings in the file. The strings should be ordered as follows:

1. When comparing two strings, compare the last character alphabetically in each string (e.g in the string "Example", the last character alphabetically is 'x').
2. Whichever string's character comes first alphabetically goes first. If the characters are the same, continue to the next character (i.e. the second to last character alphabetically, then the third to last alphabetically, etc.), repeating as necessary until one or both strings being compared runs out of characters.
3. If one string runs out of characters to compare first, it goes before the other. If they run out at the same time, they are considered equivalent and can be placed in any order.
4. Note that this program is case insensitive (e.g. the strings "example" and "eXaMpLe" are considered the same).

Look at the included examples to see what the input (`test<N>.txt`) and goal output (`goal<N>.txt`) look like.
### Compiling and Running
Use the following command to build the program:\
`javac SortingStrings.java`\
Then use this command to run the code on `<TEST_NAME>.txt`:\
`java SortingStrings <TEST_NAME>.txt`\
The results will appear in the console.