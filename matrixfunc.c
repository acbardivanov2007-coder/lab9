#include <stdio.h>
#include "matrixfunc.h"

// Функция инициализации матрицы нулями
void matrix(int matritsa[ROW][COL]) {
    // Указатель на первый элемент матрицы
    int *ukazatel = &matritsa[0][0];
    // Указатель на элемент после последнего элемента матрицы
    int *konec = ukazatel + ROW * COL;
    
    // Проходим по всем элементам матрицы и устанавливаем их в 0
    while (ukazatel < konec) {
        *ukazatel = 0;
        ukazatel++;  // Переходим к следующему элементу
    }
}

// Функция чтения матрицы из файла постолбцово снизу-вверх
void snizuverh(int matritsa[ROW][COL], const char* file) {
    // Открываем файл для чтения
    FILE *fail = fopen(file, "r");
    if (!fail) {
        printf("Oshibka otkrytiya faila %s\n", file);
        return;
    }
    
    // Читаем постолбцово снизу-вверх
    for (int stolb = 0; stolb < COL; stolb++) {
        // Указатель на нижний элемент текущего столбца
        int *ukazatel = &matritsa[ROW-1][stolb];
        // Указатель на элемент перед первым элементом столбца
        int *konec = &matritsa[0][stolb] - 1;
        
        // Двигаемся снизу вверх по столбцу
        while (ukazatel > konec) {
            // Читаем число из файла в текущий элемент
            if (fscanf(fail, "%d", ukazatel) != 1) {
                // Если не удалось прочитать, закрываем файл и выходим
                fclose(fail);
                return;
            }
            ukazatel -= 1;  // Перемещаем указатель вверх по столбцу
        }
    }
    
    // Закрываем файл
    fclose(fail);
}

// Функция вывода матрицы с индексами строк и столбцов
void indeks(int matritsa[ROW][COL]) {
    // Вывод заголовков столбцов
    printf("     ");
    for (int stolb = 0; stolb < COL; stolb++) {
        printf("[%2d] ", stolb);  // Номер столбца
    }
    printf("\n");
    
    // Вывод каждой строки матрицы
    for (int stroka = 0; stroka < ROW; stroka++) {
        printf("[%2d] ", stroka);  // Номер строки
        // Указатель на начало текущей строки
        int *ukazstroki = matritsa[stroka];
        // Указатель на элемент после последнего в строке
        int *konec = ukazstroki + COL;
        
        // Вывод всех элементов строки
        while (ukazstroki < konec) {
            printf("%4d ", *ukazstroki);  // Вывод элемента
            ukazstroki++;  // Переход к следующему элементу строки
        }
        printf("\n");  // Переход на новую строку после вывода всей строки матрицы
    }
}

// Функция поиска индексов минимального и максимального элементов матрицы
void naytiindeks(int matritsa[ROW][COL], int* rowMin, int* colMin, int* rowMax, int* colMax) {
    // Указатель на первый элемент матрицы
    int *ukazatel = &matritsa[0][0];
    // Указатель на элемент после последнего элемента матрицы
    int *konec = ukazatel + ROW * COL;
    
    // Инициализация минимального и максимального значений первым элементом
    int minim = *ukazatel;
    int maksim = *ukazatel;
    
    // Инициализация индексов минимального и максимального элементов
    *rowMin = 0;
    *colMin = 0;
    *rowMax = 0;
    *colMax = 0;
    
    int indeks = 0;  // Линейный индекс элемента
    
    // Проходим по всем элементам матрицы
    while (ukazatel < konec) {
        // Проверяем, является ли текущий элемент минимальным
        if (*ukazatel < minim) {
            minim = *ukazatel;
            // Вычисляем двумерные индексы из линейного индекса
            *rowMin = indeks / COL;
            *colMin = indeks % COL;
        }
        
        // Проверяем, является ли текущий элемент максимальным
        if (*ukazatel > maksim) {
            maksim = *ukazatel;
            // Вычисляем двумерные индексы из линейного индекса
            *rowMax = indeks / COL;
            *colMax = indeks % COL;
        }
        
        ukazatel++;  // Переход к следующему элементу
        indeks++;    // Увеличение линейного индекса
    }
}

// Функция вычисления суммы элементов выше главной диагонали (включительно)
int summa(int matritsa[ROW][COL]) {
    int summa = 0;  // Инициализация суммы
    
    // Проходим по всем строкам матрицы
    for (int stroka = 0; stroka < ROW; stroka++) {
        // Указатель на диагональный элемент текущей строки
        int *nachalo = &matritsa[stroka][stroka];
        // Указатель на элемент после последнего в строке
        int *konec = &matritsa[stroka][COL];
        
        // Суммируем элементы от диагонального до конца строки
        while (nachalo < konec) {
            summa += *nachalo;  // Добавляем текущий элемент к сумме
            nachalo++;          // Переход к следующему элементу в строке
        }
    }
    
    return summa;  // Возвращаем вычисленную сумму
}
