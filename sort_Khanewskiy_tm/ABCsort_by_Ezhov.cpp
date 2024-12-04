#include "sort_algorithms.h"
#include <iostream>
#include <string>

#define alphamin 'a'  // ����������� ������ �������� (�������� �����)
#define alphamax 'z'  // ������������ ������ �������� (�������� �����)
#define N 5       // ���������� ���� ��� ����������
#define noduplicates 0 // ���� ��� �������� ���������� (1 - �������, 0 - �� �������)
#define MAX_KEYS 1000    // ������������ ���������� �������� �����

char data[N][50];  // ������ ����� ��� ���������� (� ������������ ������ ������ 50 ��������)
long sorted_records[N];  // ������ ��� ��������������� �������
long RT[N];  // ������� �������
long LT[MAX_KEYS + 1][alphamax + 1];  // ������� ��������

// ��������� ���������� ������� � i-� ������� �����
char GetNextField(long record_no, int level) {
    return data[record_no][level - 1];
}

// ��������� ������� ������
void PutCurrRecord(long record_no) {
    static int index = 0;  // ��������� �� ������� �������
    sorted_records[index++] = record_no;
}

// ������� ��������� ������ ����� 1-�� �����
void process(int level, int keys) {
    for (char i = alphamin; i <= alphamax; ++i) {
        long recno = LT[level][i];
        LT[level][i] = 0;

        while (recno != 0) {
            if (RT[recno] == 0) {
                PutCurrRecord(recno);
                recno = 0;
                continue;
            }
            else {
                if (level == keys) {
                    while (recno != 0) {
                        PutCurrRecord(recno);
                        recno = RT[recno];
                        if (noduplicates) recno = 0;
                    }
                }
                else {
                    int newlevel = level + 1;
                    while (recno != 0) {
                        long nextrec = RT[recno];
                        char c = GetNextField(recno, newlevel);
                        RT[recno] = LT[newlevel][c];
                        LT[newlevel][c] = recno;
                        recno = nextrec;
                    }
                    process(newlevel, keys);
                }
            }
        }
    }
}

void ABCsort(int keys) {
    long start, step, stop;

    // ������������� ������� ��������
    for (int i = 0; i <= keys; ++i) {
        for (int j = 0; j <= alphamax; ++j) {
            LT[i][j] = 0;
        }
    }

    // ������������� ������� �������
    for (int i = 0; i < N; ++i) {
        RT[i] = 0;
    }

    if ((keys & 1) ^ noduplicates) {
        start = N;
        stop = -1;
        step = -1;
    }
    else {
        start = 0;
        stop = N + 1;
        step = 1;
    }

    // �������������� ������������� ������� �� ������� �������
    for (long recno = start; recno != stop; recno += step) {
        char c = GetNextField(recno, 1);
        RT[recno] = LT[1][c];
        LT[1][c] = recno;
    }

    process(1, keys);
}

int main() {
    // ��������� ������ ������ (��������, ����� ��������� ������ ��� ������ �� �������)
    for (int i = 1; i < N + 1; ++i) {
        std::string word;
        std::cin >> word;
        for (int j = 0; j < word.length(); ++j) {
            data[i][j] = word[j];
        }
        data[i][word.length()] = '\0';  // ����������� ������� ������
    }

    // �������� ���������� (����������, ��������, 3 �������� ����)
    ABCsort(MAX_KEYS);

    // ����� ��������������� ������
    std::cout << "��������������� ������:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << data[sorted_records[i]] << std::endl;
    }

    return 0;
}