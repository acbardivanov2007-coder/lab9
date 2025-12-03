#include <stdio.h>
#include "matrixfunc.h"

int vvod_snizu_vverh_stdin(int matrica[ROW][COL]) {
    
    int cou = 0;
    
    // Постолбцовый ввод снизу-вверх из stdin
    for (int y = 0; y < COL; y++) {
        int *col_ptr = *matrica + y;  // Указатель на первый элемент столбца y
        
        // Идем снизу вверх по столбцу
        for (int x = ROW - 1; x >= 0; x--) {
            if (scanf("%d", col_ptr + x * COL) != 1) {
                printf("Не получается прочитать данные. Прочитано %d элементов.\n", cou);
                return cou;
            }
            cou++;
        }
    }
    
    printf("Матрица считана, считано всего %d элементов\n", cou);
    return cou;
}

void vivod(int matrica[ROW][COL]) {
    printf("Матрица %d на %d:\n", ROW, COL);
    
    int (*row_ptr)[COL] = matrica;  // Указатель на строки
    
    for (int x = 0; x < ROW; x++) {
        int *element_ptr = *(row_ptr + x);  // Указатель на элементы строки
        
        for (int y = 0; y < COL; y++) {
            printf("%8d", *(element_ptr + y));
        }
        printf("\n");
    }
}

void find_min_max(int matrica[ROW][COL], int* min_row, int* min_col, 
                  int* max_row, int* max_col) {
    // Инициализируем первым элементом матрицы
    int *first_element = *matrica;
    int min_val = *first_element;
    int max_val = *first_element;
    
    *min_row = *min_col = *max_row = *max_col = 0;
    
    int (*row_ptr)[COL] = matrica;
    
    for (int x = 0; x < ROW; x++) {
        int *element_ptr = *(row_ptr + x);
        
        for (int y = 0; y < COL; y++) {
            int current = *(element_ptr + y);
            
            if (current < min_val) {
                min_val = current;
                *min_row = x;
                *min_col = y;
            }
            
            if (current > max_val) {
                max_val = current;
                *max_row = x;
                *max_col = y;
            }
        }
    }
    
    printf("Минимальный элемент: матрица[%d][%d] = %d\n", 
           *min_row, *min_col, min_val);
    printf("Максимальный элемент: матрица[%d][%d] = %d\n", 
           *max_row, *max_col, max_val);
}

int sum_diagonal(int matrica[ROW][COL]) {
    int sum = 0;
    int (*row_ptr)[COL] = matrica;
    
    for (int x = 0; x < ROW; x++) {
        int *element_ptr = *(row_ptr + x);
        
        // Начинаем с столбца x (элементы на главной диагонали и выше)
        for (int y = x; y < COL; y++) {
            sum += *(element_ptr + y);
        }
    }
    
    return sum;
}

void print_menu() {
    printf("a. Функция 1 (Постолбцовый ввод снизу-вверх)\n");
    printf("b. Представление массива (матрица значений)\n");
    printf("c. Функция 2 (Найти мин и макс элементы)\n");
    printf("d. Функция 3 (Сумма выше главной диагонали)\n");
    printf("e. Выход\n");
    printf("Выберите опцию (a-e): ");
}
