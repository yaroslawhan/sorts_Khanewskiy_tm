#include "sort_algorithms.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

constexpr char alphamin = 'a';
constexpr char alphamax = 'z';

char GetNextField(const std::vector<std::string>& data, long record_no, int level) {
    if (level - 1 < data[record_no].size())
        return data[record_no][level - 1];
    return '\0';
}

void PutCurrRecord(std::vector<long>& sorted_records, long record_no, int& index) {
    sorted_records[index++] = record_no;
}

void process(std::vector<long>& RT, std::vector<std::vector<long>>& LT, std::vector<long>& sorted_records,
    const std::vector<std::string>& data, int level, int keys, int& index) {
    for (char i = alphamin; i <= alphamax; ++i) {
        long recno = LT[level][i];
        LT[level][i] = 0;

        while (recno != 0) {
            if (RT[recno] == 0) {
                PutCurrRecord(sorted_records, recno, index);
                recno = 0;
                continue;
            }
            else {
                if (level == keys) {
                    while (recno != 0) {
                        PutCurrRecord(sorted_records, recno, index);
                        recno = RT[recno];
                    }
                }
                else {
                    int newlevel = level + 1;
                    while (recno != 0) {
                        long nextrec = RT[recno];
                        char c = GetNextField(data, recno, newlevel);
                        RT[recno] = LT[newlevel][c];
                        LT[newlevel][c] = recno;
                        recno = nextrec;
                    }
                    process(RT, LT, sorted_records, data, newlevel, keys, index);
                }
            }
        }
    }
}

std::string ABCsort_by_Ezhov(const std::string& input) {
    int keys = 10;
    std::vector<std::string> data;
    std::vector<long> sorted_records;
    std::vector<long> RT;
    std::vector<std::vector<long>> LT(keys + 1, std::vector<long>(alphamax + 1, 0));

    std::string word;
    std::istringstream stream(input);
    data.push_back("");
    while (stream >> word) {
        data.push_back(word);
    }

    int N = data.size();
    sorted_records.resize(N, 0);
    RT.resize(N, 0);

    for (int recno = 0; recno < N; ++recno) {
        char c = GetNextField(data, recno, 1);
        RT[recno] = LT[1][c];
        LT[1][c] = recno;
    }

    int index = 0;
    process(RT, LT, sorted_records, data, 1, keys, index);

    std::ostringstream result;
    for (int i = 0; i < N; ++i) {
        result << data[sorted_records[i]];
        if (i < N - 1) {
            result << " ";
        }
    }

    return result.str();
}
