
#include "ABCSort_by_Ezhov.h"
#include <unordered_map>

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