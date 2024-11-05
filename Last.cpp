#include <iostream>
#include <vector>
#include <string>
#include "ABCSort_by_Ezhov.h"

using namespace std;

int main() {
    string input = "apple banana grape pear orange kiwi apricot";
    vector<string> sortedWords = ABCSort(input);

    cout << "Отсортированные слова:" << endl;
    for (const auto& word : sortedWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}