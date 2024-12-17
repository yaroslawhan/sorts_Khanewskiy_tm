#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

// ��������� ��������� ����
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

// ������� ��� ��������� ��������� ������ � �������� ����������� ����
std::string generateString(int wordCount) {
    std::string result;
    for (int i = 0; i < wordCount; ++i) {
        result += generateRandomWord();
        if (i != wordCount - 1) result += " ";
    }
    return result;
}

// ������� ��� ��������� ������ � ��������� ����������� ���� � ������ ��������������� ����
std::string generatePartiallySortedString(size_t totalWords, size_t sortedWords) {
    // �������� �� ������������ ����������
    if (sortedWords > totalWords) {
        return "";
    }

    // ������� ������ ����
    std::vector<std::string> words;
    for (size_t i = 0; i < totalWords; ++i) {
        words.push_back(generateRandomWord());
    }

    // ��������� ��������� ���������� ����
    if (sortedWords > 0) {
        std::sort(words.begin(), words.begin() + sortedWords);
    }

    // �������� ������ �� ������� ����
    std::string result;
    for (size_t i = 0; i < totalWords; ++i) {
        result += words[i];
        if (i != totalWords - 1) result += " ";
    }

    return result;
}
