#include "ABCSort_by_Ezhov.h"
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> ABCSort(const vector<string>& collection, int rank) {
    if (collection.size() < 2) return collection;

    unordered_map<char, vector<string>> table;
    vector<string> listResult;
    int shortWordsCounter = 0;

    for (const auto& str : collection) {
        if (rank < str.length()) {
            table[str[rank]].push_back(str);
        }
        else {
            listResult.push_back(str);
            shortWordsCounter++;
        }
    }

    if (shortWordsCounter == collection.size()) return collection;

    for (char i = 'A'; i <= 'z'; i++) {
        if (table.count(i)) {
            auto sortedWords = ABCSort(table[i], rank + 1);
            listResult.insert(listResult.end(), sortedWords.begin(), sortedWords.end());
        }
    }

    return listResult;
}

// Функция для разбивания строки на слова и сортировки
vector<string> ABCSort(const string& input) {
    vector<string> words;
    stringstream ss(input);
    string word;

    // Разбиваем строку на слова
    while (ss >> word) {
        words.push_back(word);
    }

    // Сортируем слова с помощью уже существующей функции ABCSort
    return ABCSort(words, 0);
}