#include "sort_algorithms.h" 
#include <unordered_map> 
#include <sstream> 

using namespace std;

vector<string> ABCsort_by_Ezhov(const vector<string>& collection, int rank) {
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
            auto sortedWords = ABCsort_by_Ezhov(table[i], rank + 1);
            listResult.insert(listResult.end(), sortedWords.begin(), sortedWords.end());
        }
    }

    return listResult;
}


string ABCsort_by_Ezhov(const string& input) {
    vector<string> words, res;
    stringstream ss(input);
    string word, resstr;

    while (ss >> word) {
        words.push_back(word);
    }

    res = ABCsort_by_Ezhov(words, 0);

    for (size_t i = 0; i < res.size(); ++i) {
        resstr += res[i];
        if (i != res.size() - 1) {
            resstr += " ";
        }
    }

    return resstr;
}