#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

// Константы для размеров матрицы
#define COL 10  // количество столбцов
#define ROW 10  // Количество строк

// Прототипы функций

// Инициализация матрицы нулями
void matrix(int matritsa[ROW][COL]);

// a. Постолбцовый ввод снизу-вверх из файла
void snizuverh(int matritsa[ROW][COL], const char* file);

// b. Вывод матрицы с индексами
void indeks(int matritsa[ROW][COL]);

// c. Поиск индексов минимального и максимального элементов
void naytiindeks(int matritsa[ROW][COL], int* rowMin, int* colMin, int* rowMax, int* colMax);

// d. Сумма элементов выше главной диагонали (включительно)
int summa(int matritsa[ROW][COL]);

#endif 
