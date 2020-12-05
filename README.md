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