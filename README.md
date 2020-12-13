# CSC212-Project

To compile and run: g++ -std=c++11 -Wall main.cpp -o main && ./main best.txt worst.txt random.txt large.txt

main.cpp will read the data from the text files and store them into a vector of vectors for containing the different
datasets used by each sorting algorithm. The sorting algorithms available in main.cpp are:
1. Insertion sort
2. Quick sort
3. Merge sort
4. Heap sort

Additionally, 4 test cases are available to use for testing each respective sorting algorithm. For each sorting algorithm,
it will provide statistics about the number of comparisons and swaps, as well as the time that it took for each algorithm into the console.

The tests will run the following algorithms in the order: insertion, quick, merge, heap
for each test case.

EDIT 12/13/2020:
main.cpp has been reconfigured, updated version is called master.cpp.  Now, each sorting algorithm is on its own .cpp file and include directives were added to the new master.cpp to make master.cpp easier to read.  Some print statements have been added/removed to help readability of the command line output as well.

To compile and run: g++ -std=c++11 -Wall master.cpp -o master && ./master best.txt worst.txt random.txt large.txt
