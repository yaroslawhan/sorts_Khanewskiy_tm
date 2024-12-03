#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string quickSort_by_Usynin(std::string& str) {
    // Split string into words
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Internal function to perform QuickSort on the words vector
    auto quickSort = [&](int low, int high, auto& quickSortRef) -> void {
        if (low < high) {
            std::string pivot = words[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (words[j] < pivot) {
                    i++;
                    std::swap(words[i], words[j]);
                }
            }
            std::swap(words[i + 1], words[high]);
            int pi = i + 1;

            // Recursively sort elements before and after partition
            quickSortRef(low, pi - 1, quickSortRef);
            quickSortRef(pi + 1, high, quickSortRef);
        }
        };

    // Start sorting using the lambda function
    quickSort(0, words.size() - 1, quickSort);

    // Reconstruct the string from sorted words
    str.clear();
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) str += " ";
        str += words[i];
    }
    return str;
}
