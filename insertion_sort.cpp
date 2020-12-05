#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

// ./insertion_sort best.txt worst.txt average.txt large.txt

void write_data(std::string fname, std::vector<std::vector<int>> &test_cases);
void print_data(std::vector<int> &data);
void insertion_sort(std::vector<int> &data);
void swap(std::vector<int> &data, int j);

int main(int argc, char **argv) {

    // Test cases are stored in a vector of vectors like this:
    // test_cases[0] = best
    // test_cases[1] = worst
    // test_cases[2] = average
    // test_cases[3] = large
    std::vector<std::vector<int>> test_cases;
    for (int i = 0; i < argc - 1; i++) {
        write_data(argv[i + 1], test_cases);

    }

    // Debugging print to make sure data written to vectors correctly
    // for (int i = 0; i < argc - 1; i++) {
    //     std::cout << argv[i + 1] << "\n";
    //     print_data(test_cases[i]);
    // }

    for (int i = 0; i < test_cases.size(); i++) {
        std::cout << argv[i + 1] << " stats:\n";
        insertion_sort(test_cases[i]);
        // print_data(test_cases[i]);
        std::cout << "\n";
    }

    return 0;
}

// Takes the input file from the command line and a pointer to test_cases vector to write that
// data to its corresponding position in the vector
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

// Print function to display data from a single data set (Ex. print_data(test_cases[i]))
void print_data(std::vector<int> &data) {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";

    }
    std::cout << "\n";
}

void insertion_sort(std::vector<int> &data) {
    int num_comparisons = 0;
    int num_swaps = 0;

    for (int i = 0; i < data.size(); i++) {
        for (int j = i; j > 0; j--) {
            num_comparisons++;
            if (data[j] < data[j - 1]) {
                num_swaps++;
                std::swap(data, j);
            } else {
                break;
            }
        }
    }
    std::cout << "Number of Comparisons: " << num_comparisons << "\nNumber of Swaps: " << num_swaps << "\n";
}

// Swap function
void swap(std::vector<int> &data, int j) {
    int temp = data[j];
    data[j] = data[j - 1];
    data[j - 1] = temp;

}

