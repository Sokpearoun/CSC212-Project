#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <time.h>

// run this: ./main best.txt worst.txt random.txt large.txt

// ============================================================================================================================
// Quick Sort Function Declarations =============================================================================================
// ============================================================================================================================
int Partition(std::vector<int> & array, int left, int right, int &num_comparisons, int &num_swaps);
void QSort(std::vector<int> & array, int left, int right, int &num_comparisons, int &num_swaps);
void quickSort(std::vector<int> & array);
// ============================================================================================================================
// Insertion Sort Function Declarations =============================================================================================
// ============================================================================================================================
void insertion_sort(std::vector<int> &data);
// ============================================================================================================================
// Merge Sort Function Declarations =============================================================================================
// ============================================================================================================================
void mergeSortDriver(std::vector<int>& array);
void mergeSort(std::vector<int>& array, int left, int right, int& num_comparisons, int& num_swaps);
void merge(std::vector<int>& array, int left, int mid, int right, int& num_comparisons, int& num_swaps);
// ============================================================================================================================
// Heap Sort Function Declarations =============================================================================================
// ============================================================================================================================
void max_heapify(std::vector<int>& arr, int size, int i, int & compCounter, int & swapCounter);
void heap_sort(std::vector<int>& arr);
// ============================================================================================================================
// Other Function Declarations =============================================================================================
// ============================================================================================================================
void swap(std::vector<int> &data, int j);
void write_data(std::string fname, std::vector<std::vector<int>> &test_cases);
void print_data(std::vector<int> &data);
// ============================================================================================================================
// Main ============================================================================================================================
// ============================================================================================================================

int main(int argc, char** argv) {

    std::vector<std::vector<int>> insertion;
    std::vector<std::vector<int>> quick;
    std::vector<std::vector<int>> merge;
    std::vector<std::vector<int>> heap;

    // write separate datasets for each algorithm to their own vector of vectors
    for (int i = 0; i < argc - 1; i++) {
        write_data(argv[i + 1], insertion);
        write_data(argv[i + 1], quick);
        write_data(argv[i + 1], merge);
        write_data(argv[i + 1], heap);
    }

    std::cout << "=======================================================================================================\n";
    for (int i = 0; i < argc - 1; i++) {

        // insertion sort
        std::cout << argv[i + 1];
        std::cout << "\nInsertion Sort Stats:\n";
        insertion_sort(insertion[i]);
        std::cout << "\n";
        std::cout << "*****************************************************************************************************\n";
        // quick sort
        std::cout << "\nQuick Sort Stats:\n";
        quickSort(quick[i]);
        std::cout << "\n";
        std::cout << "*****************************************************************************************************\n";
        // merge sort
        std::cout << "\nMerge Sort Stats:\n";
        mergeSortDriver(merge[i]);
        std::cout << "\n";
        std::cout << "*****************************************************************************************************\n";
        // heap sort
        std::cout << "\nHeap Sort Stats:\n";
        heap_sort(heap[i]);
        std::cout << "\n";

        std::cout << "=======================================================================================================\n";
    }

    return 0;
}

// ============================================================================================================================
// End of Main ============================================================================================================================
// ============================================================================================================================

// ============================================================================================================================
// Quick Sort Function Definitions =============================================================================================
// ============================================================================================================================
int Partition(std::vector<int> & array, int left, int right, int &num_comparisons, int &num_swaps){

	int key = array[left];
	while (left < right){
		num_comparisons++;
		while (left < right && array[right] >= key){
			right--;
		}
		std::swap(array[left], array[right]);
		num_swaps++;
		while (left < right && array[left] <= key){
			left ++;
		}
		std::swap(array[left], array[right]);
		num_swaps++;
	}
	return left;
}

void QSort(std::vector<int> & array, int left, int right, int &num_comparisons, int &num_swaps){
	int pivot;
	if (left < right){
	    pivot = Partition(array, left, right, num_comparisons, num_swaps);
		QSort(array, left, pivot - 1, num_comparisons, num_swaps);
		QSort(array, pivot + 1, right, num_comparisons, num_swaps);
	}
}

void quickSort(std::vector<int> & array){
    unsigned long c_start, c_end;
    int num_comparisons = 0;
    int num_swaps = 0;

    c_start = std::clock();
	QSort(array, 0, array.size()-1, num_comparisons, num_swaps);
	c_end = std::clock();

	std::cout << "Start: " << c_start << "\nEnd: " << c_end << "\n";

    std::cout << "\tNumber of Comparisons: " << num_comparisons << "\n\tNumber of Swaps: " << num_swaps << "\n";
    std::cout << "\tRun Time: " << std::fixed << std::setprecision(8) << 1.0 * (c_end - c_start)/CLOCKS_PER_SEC << "\n";
}

// ============================================================================================================================
// Insertion Sort Function Definitions =============================================================================================
// ============================================================================================================================
void insertion_sort(std::vector<int> &data) {
    unsigned long c_start, c_end;
    int num_comparisons = 0;
    int num_swaps = 0;

    c_start = std::clock();
    for (int i = 0; i < data.size(); i++) {
        for (int j = i; j > 0; j--) {
            num_comparisons++;
            if (data[j] < data[j - 1]) {
                num_swaps++;
                std::swap(data[j], data[j - 1]);
            } else {
                break;
            }
        }
    }
    c_end = std::clock();

    std::cout << "Start: " << c_start << "\nEnd: " << c_end << "\n";

    std::cout << "\tNumber of Comparisons: " << num_comparisons << "\n\tNumber of Swaps: " << num_swaps << "\n";
    std::cout << "\tRun Time: " << std::fixed << std::setprecision(8) << 1.0 * (c_end - c_start)/CLOCKS_PER_SEC << "\n";

}

// ============================================================================================================================
// Merge Sort Function Definitions =============================================================================================
// ============================================================================================================================
void mergeSortDriver(std::vector<int>& array) {
    int num_comparisons = 0;
    int num_swaps = 0;
    int left = 0;
    int right = array.size() - 1;
    unsigned long c_start = std::clock();
    mergeSort(array, left, right, num_comparisons, num_swaps);
    unsigned long c_end = std::clock();

    std::cout << "Start: " << c_start << "\nEnd: " << c_end << "\n";

    std::cout << "\tNumber of Comparisons: " << num_comparisons << "\n\tNumber of Swaps: " << num_swaps << "\n";
	std::cout << "\tRun Time: " << std::fixed << std::setprecision(8) << 1.0 * (c_end - c_start)/CLOCKS_PER_SEC << "\n";
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

// ============================================================================================================================
// Heap Sort Function Definitions =============================================================================================
// ============================================================================================================================
void max_heapify(std::vector<int>& arr, int size, int i, int & compCounter, int & swapCounter){
    int largest;
    int left = (2*i) + 1;
    int right = left + 1;

    if(left < size && arr[left] > arr[i]){
        compCounter++;
        largest = left;
    }
    else{
        largest = i;
    }

    if(right < size && arr[right] > arr[largest]){
        compCounter++;
        largest = right;
    }

    if(largest != i){
        swapCounter++;
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, size, largest, compCounter, swapCounter);
    }
}

void heap_sort(std::vector<int>& arr){
    // declare the counters
    int n = arr.size();
    int compCounter = 0;
    int swapCounter = 0;

    // clock variables
    unsigned long c_start, c_end;

    c_start = std::clock();
    for(int i = (n / 2 - 1); i >= 0; i--){
       max_heapify(arr, n, i, compCounter, swapCounter);
    }

    for(int i = n - 1; i >= 0; i--){
        swapCounter++;
        std::swap(arr[0], arr[i]);
        n--;
        max_heapify(arr, n, 0, compCounter, swapCounter);
    }
    c_end = std::clock();

    std::cout << "Start: " << c_start << "\nEnd: " << c_end << "\n";
    std::cout << "\tNumber of Comparisons: " << compCounter << "\n\tNumber of Swaps: " << swapCounter << "\n";
    std::cout << "\tRun Time: " << std::fixed << std::setprecision(8) << 1.0 * (c_end - c_start)/CLOCKS_PER_SEC << "\n";
}


// ============================================================================================================================
// Other Function Definitions =================================================================================================
// ============================================================================================================================
void write_data(std::string fname, std::vector<std::vector<int>> &test_cases) {

    std::ifstream myFile;
    myFile.open(fname, std::ifstream::in);
    std::string val;

    // Dynamic memory on the heap, new vector declared
    std::vector<int> *data = new std::vector<int>;

    while(std::getline(myFile, val, ',')) {
        // std::cout << val << "\n";
        data->push_back(std::stoi(val));
    }

    test_cases.push_back(*data);

    // Delete dynamic data storage to prevent data leak
    delete data;

}

void print_data(std::vector<int> &data) {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";

    }
    std::cout << "\n";
}
