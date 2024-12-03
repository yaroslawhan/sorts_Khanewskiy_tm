#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

#include "sort_algorithms.h"

#define RUN(x, show_sort) {                \
    Run(#x, x, data, show_sort);           \
}

std::string dataset;

template<typename SortingMethod>
void Run(const std::string& method_name, SortingMethod sortingMethod, const std::string& inputData, bool showResult = false) {
    std::cout << "Now " << method_name << " is running...\n";

    const auto start = std::chrono::high_resolution_clock::now();
    std::string outputData = "test1 trst2 test 3 1 gg aa b ccc";
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    //bool is_sorted = std::is_sorted(data.begin(), data.end());

    std::cout << "Algorithm " << "completed successfully.\n";
    std::cout << "Required time: " << time << " mcs.\n\n";

    if (showResult) std::cout << "Resulted string after sorting: " << outputData << '\n';
}

int main() {
    std::string data;

    std::ifstream inputFile("test_data.txt");
    if (inputFile) {
        std::getline(inputFile, data);
        inputFile.close();
    } else std::cout << "Error while reading the file! Try again";

    std::cout << "-------- Comparison of algorithms for sorting string --------\n";
    
    std::cout << "Input string: " << data << "\n\n";

    RUN(quickSort_by_Usynin, true);

    std::cout << "Press Enter to exit...";
    return 0;
}