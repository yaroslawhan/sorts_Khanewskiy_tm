#include "sort_algorithms.h"

#ifndef SSTREAM_H
#define SSTREAM_H
#include <sstream>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

using namespace std;

// Вспомогательная функция для перестройки кучи
void heapify_Legkova(vector<string>& words, unsigned n, unsigned i) {
    unsigned largest = i;      // Инициализируем largest как корень
    unsigned left = 2 * i + 1; // Левый = 2*i + 1
    unsigned right = 2 * i + 2; // Правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && words[left] > words[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше текущего largest
    if (right < n && words[right] > words[largest]) {
        largest = right;
    }

    // Если largest не корень
    if (largest != i) {
        swap(words[i], words[largest]); // Меняем местами
        heapify_Legkova(words, n, largest); // Рекурсивно перестраиваем кучу
    }
}

// Функция для сортировки слов методом "сортировка кучей"
string heap_by_Legkova(string input) {
    // Разбиваем строку на слова
    vector<string> words;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    unsigned n = words.size();

    // Строим кучу
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify_Legkova(words, n, i);
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; --i) {
        swap(words[0], words[i]); // Меняем местами корень с последним элементом
        heapify_Legkova(words, i, 0); // Перестраиваем кучу из оставшихся элементов
    }

    // Собираем отсортированные слова обратно в строку
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}