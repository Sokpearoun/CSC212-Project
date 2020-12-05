#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void mergeSortDriver(std::vector<int>& array);
void mergeSort(std::vector<int>& array, int left, int right, int& num_comparisons, int& num_swaps);
void merge(std::vector<int>& array, int left, int mid, int right, int& num_comparisons, int& num_swaps);
void write_data(std::string fname, std::vector<int>& test_case);
void read_data(std::vector<int> test_case);

int main(int argc, char* argv[]) {
    std::string fname(argv[1]);
    std::vector<int> datapoints;
    write_data(fname, datapoints);
    //mergeSortDriver(datapoints);
    quickSort(datapoints);
    //read_data(datapoints);
    return 0;
}

void mergeSortDriver(std::vector<int>& array) {
    int num_comparisons = 0;
    int num_swaps = 0;
    int left = 0;
    int right = array.size() - 1;
    double c_start = std::clock();
    mergeSort(array, left, right, num_comparisons, num_swaps);
    double c_end = std::clock();

    std::cout << "\tNumber of Comparisons: " << num_comparisons << "\n\tNumber of Swaps: " << num_swaps << "\n";
	std::cout << "\tRun Time: " << std::fixed << std::setprecision(4) << (c_end - c_start)/CLOCKS_PER_SEC << "\n";
}

void mergeSort(std::vector<int>& array, int left, int right, int& num_comparisons, int& num_swaps) {
    int mid = (left + (right - 1))/2;
    // Repeatedly break down the vect by half until there is only one value left.
    if (left < right) {
        mergeSort(array, left, mid, num_comparisons, num_swaps);
        mergeSort(array, mid + 1, right, num_comparisons, num_swaps);
        // Merge the broken down vect, sorting it during the process
        merge(array, left, mid, right, num_comparisons, num_swaps);
    }
    else return;
}

void merge(std::vector<int>& array, int left, int mid, int right, int& num_comparisons, int& num_swaps) {
    // Create temp left and right vectors
    int sizeLeft = (mid - left) + 1;
    int sizeRight = (right - mid);
    std::vector<int> leftVect;
    std::vector<int> rightVect;
    // Place values left of mid + mid into leftVect
    for (int i = left; i < left + sizeLeft; i++) {
        leftVect.push_back(array[i]);
    }
    // Place values right of mid into rightVect
    for (int i = mid + 1; i < mid + 1 + sizeRight; i++) {
        rightVect.push_back(array[i]);
    }
    // Now place values in temp into original by correct order
    int pos = left; // Starting index for original vect
    int i = 0; // Temp left index
    int j = 0; // Temp right index

    while (i < sizeLeft && j < sizeRight) {
        // Compare values of leftVect with rightVect
        num_comparisons++;
        if (leftVect[i] > rightVect[j]) {
            // rightVect carries a smaller value
            // place value into original vect
            array[pos] = rightVect[j];
            //std::cout << " leftVect = " << leftVect[i] << " rightVect = " << rightVect[j] << " i =" << i << " j = " << j << " pos = " << pos << std::endl;
            j++;
            num_swaps++;
        }
        else {
            // leftVect carries a smaller value
            // place value into original vect
            array[pos] = leftVect[i];
            i++;
        }
        pos++;
    }
    // Get rid of remaining values from leftVect
    while (i < sizeLeft) {
        array[pos] = leftVect[i];
        i++;
        pos++;

    }
    // Get rid of remaining values from rightVect
    while (j < sizeRight) {
        array[pos] = rightVect[j];
        j++;
        pos++;
    }

    return;
}

void write_data(std::string fname, std::vector<int>& test_case) {

    std::ifstream myFile;
    myFile.open(fname, std::ifstream::in);
    std::string val;

    // Dynamic memory on the heap, new vector declared
    std::vector<int> data;

    while(std::getline(myFile, val, ',')) {
        //std::cout << val << "\n";
        //std::cout << test_case.size() << ' ';

        test_case.push_back(std::stoi(val));
    }

    // Delete dynamic data storage to prevent data leak
}

void read_data(std::vector<int> test_case) {
    for (int i = 0; i < test_case.size(); i++) {
        std::cout << test_case[i] << ' ';
    }

}