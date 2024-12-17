#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

#include "sort_algorithms.h"
#include "dataGenerator.h"

#define RUN(x, show_sort) {                \
    Run(#x, x, data, show_sort);           \
}

std::string dataset;

template<typename SortingMethod>
void Run(const std::string& method_name, SortingMethod sortingMethod, std::string& inputData, bool showResult = false) {
    std::cout << "Now " << method_name << " is running...\n";

    const auto start = std::chrono::high_resolution_clock::now();
    std::string outputData = sortingMethod(inputData);
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    std::cout << "Algorithm completed successfully.\n";
    std::cout << "Required time: " << time << " ms.\n\n";

    if (showResult) std::cout << "Resulted string after sorting: " << outputData << '\n';
}

int main() {
    std::string data;
    std::srand(std::time(nullptr)); // »нициализаци€ генератора случайных чисел

    std::cout << "-------- Comparison of algorithms for sorting string --------\n\n\n";
    
    /*std::cout << "10.000 words\n\n";
    data = generateString(10000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);

    std::cout << "\n\n100.000 words\n\n";
    data = generateString(100000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);

    std::cout << "\n\n1.000.000 words\n\n";
    data = generateString(1000000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);*/


    std::cout << "\n\nPartially sorted string:" << "\n10.000 words\n\n";
    data = generatePartiallySortedString(10000, 5000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);

    std::cout << "\n\n100.000 words\n\n";
    data = generatePartiallySortedString(100000, 50000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);

    std::cout << "\n\n1.000.000 words\n\n";
    data = generatePartiallySortedString(1000000, 500000);
    RUN(quickSort_by_Usynin, false);
    RUN(ABCsort_by_Ezhov, false);
    RUN(heap_by_Legkova, false);
    RUN(inserts_by_Omelchenko, false);

    return 0;
}