#include "sort_algorithms.h"
#include <iostream>
#include <string>

#define alphamin 'a'  // Минимальный символ алфавита (строчные буквы)
#define alphamax 'z'  // Максимальный символ алфавита (строчные буквы)
#define N 5       // Количество слов для сортировки
#define noduplicates 0 // Флаг для удаления дубликатов (1 - удалять, 0 - не удалять)
#define MAX_KEYS 1000    // Максимальное количество ключевых полей

char data[N][50];  // Массив строк для сортировки (с максимальной длиной строки 50 символов)
long sorted_records[N];  // Массив для отсортированных записей
long RT[N];  // Таблица записей
long LT[MAX_KEYS + 1][alphamax + 1];  // Таблица символов

// Получение следующего символа в i-м разряде слова
char GetNextField(long record_no, int level) {
    return data[record_no][level - 1];
}

// Обработка текущей записи
void PutCurrRecord(long record_no) {
    static int index = 0;  // Указатель на текущую позицию
    sorted_records[index++] = record_no;
}

// Функция обработки данных после 1-го этапа
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

    // Инициализация таблицы символов
    for (int i = 0; i <= keys; ++i) {
        for (int j = 0; j <= alphamax; ++j) {
            LT[i][j] = 0;
        }
    }

    // Инициализация таблицы записей
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

    // Первоначальное распределение записей по первому символу
    for (long recno = start; recno != stop; recno += step) {
        char c = GetNextField(recno, 1);
        RT[recno] = LT[1][c];
        LT[1][c] = recno;
    }

    process(1, keys);
}

int main() {
    // Заполняем массив данных (например, можно загрузить строки или задать их вручную)
    for (int i = 1; i < N + 1; ++i) {
        std::string word;
        std::cin >> word;
        for (int j = 0; j < word.length(); ++j) {
            data[i][j] = word[j];
        }
        data[i][word.length()] = '\0';  // Завершающий нулевой символ
    }

    // Вызываем сортировку (используем, например, 3 ключевых поля)
    ABCsort(MAX_KEYS);

    // Вывод отсортированных данных
    std::cout << "Отсортированные данные:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << data[sorted_records[i]] << std::endl;
    }

    return 0;
}