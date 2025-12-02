#include <stdio.h>
#include "matrixfunc.h"

int main() {
    int matrica[ROW][COL] = {{0}};  // Инициализация нулями
    char choice;
    int cou, sum;
    int min_row, min_col, max_row, max_col;
    
    // Автоматически читаем матрицу из stdin при запуске
    printf("=== Чтение матрицы из стандартного ввода ===\n");
    cou = vvod_snizu_vverh_stdin(matrica);
    
    if (cou != ROW * COL) {
        printf("Ошибка: не удалось считать полную матрицу. Требуется %d элементов, считано %d\n", 
               ROW * COL, cou);
        return 1;
    }
    
    do {
        print_menu();
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'a':
                printf("Матрица уже была считана при запуске программы.\n");
                printf("Если хотите ввести новую, перезапустите программу.\n");
                break;
                
            case 'b':
                vivod(matrica);
                break;
                
            case 'c':
                find_min_max(matrica, &min_row, &min_col, &max_row, &max_col);
                break;
                
            case 'd':
                sum = sum_diagonal(matrica);
                printf("Сумма всех значений выше главной диагонали (включительно): %d\n", sum);
                break;
                
            case 'e':
                printf("Выход из программы.\n");
                break;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }
        
        if (choice != 'e') {
            printf("\nНажмите Enter для продолжения...");
            getchar(); // Очистка буфера от '\n'
            getchar(); // Ожидание нажатия Enter
        }
        
    } while (choice != 'e');
    
    return 0;
}
