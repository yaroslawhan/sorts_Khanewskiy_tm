#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <sort_algorithms.h>

using namespace std;

string inserts_by_Omelchenko(string str) {
    // Разбиваем строку на слова
    stringstream ss(str);
    string word;
    vector<string> words;
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }

    // Сортировка вставкой
    int n = words.size();
    for (int i = 1; i < n; ++i) {
        string key = words[i];
        int j = i - 1;

        // Сдвиг элементов, больших, чем ключ, вправо
        while (j >= 0 && words[j] > key) {
            words[j + 1] = words[j];
            j--;
        }

        // Вставка ключа в правильную позицию
        words[j + 1] = key;
    }

    // Собираем строку обратно
    stringstream result;
    for (const auto& word : words) {
        result << word << " ";
    }
    return result.str();
}


