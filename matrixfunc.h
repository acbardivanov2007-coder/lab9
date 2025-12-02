#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

#define COL 10
#define ROW 10

// Функция 1: Постолбцовый ввод снизу-вверх из stdin
int vvod_snizu_vverh_stdin(int matrica[ROW][COL]);

// Функция представления массива (матрица значений)
void vivod(int matrica[ROW][COL]);

// Функция 2: Определение индексов максимального и минимального элементов
void find_min_max(int matrica[ROW][COL], int* min_row, int* min_col, 
                  int* max_row, int* max_col);

// Функция 3: Сумма всех значений выше главной диагонали (включительно)
int sum_diagonal(int matrica[ROW][COL]);

// Вспомогательная функция для вывода меню
void print_menu();

#endif
