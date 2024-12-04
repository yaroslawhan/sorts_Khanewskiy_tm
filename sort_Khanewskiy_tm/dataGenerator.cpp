#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Генератор случайных слов
std::string generateRandomWord() {
    int wordLength = 3 + rand() % 8;
    std::string word;
    for (int i = 0; i < wordLength; ++i) {
        int charType = rand() % 62;
        char ch;
        if (charType < 10) {
            ch = '0' + charType;
        }
        else if (charType < 36) {
            ch = 'A' + (charType - 10);
        }
        else {
            ch = 'a' + (charType - 36);
        }
        word += ch;
    }
    return word;
}

// Функция для генерации строки с заданным количеством слов
std::string generateString(int wordCount) {
    std::string result;
    for (int i = 0; i < wordCount; ++i) {
        result += generateRandomWord();
        if (i != wordCount - 1) result += " ";
    }
    return result;
}