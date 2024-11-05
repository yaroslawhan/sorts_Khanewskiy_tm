#include "inserts_by_Omelchenko.h"

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#ifndef SSTREAM_H
#define SSTREAM_H
#include <sstream>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

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