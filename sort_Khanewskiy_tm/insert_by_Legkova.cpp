#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Объединенная функция insert_by_Legkova для сортировки слов методом "сортировка кучей"
string insert_by_Legkova(string input) {
    // Разбиваем строку на слова
    vector<string> words;
    stringstream ss(input);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    unsigned n = words.size();

    // Встроенная функция для перестройки кучи
    auto heapify = [&](unsigned n, unsigned i) {
        unsigned largest = i;
        unsigned left = 2 * i + 1;
        unsigned right = 2 * i + 2;

        if (left < n && words[left] > words[largest]) {
            largest = left;
        }
        if (right < n && words[right] > words[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(words[i], words[largest]);
            heapify(n, largest);
        }
        };

    // Строим кучу
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; --i) {
        swap(words[0], words[i]);
        heapify(i, 0);
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

// Функция main для проверки
int main() {
    string input = "сортировка слов методом кучей пример";
    string sorted_string = insert_by_Legkova(input);

    cout << "Отсортированная строка: " << sorted_string << endl;
    return 0;
}
