#include <stdio.h>
#include "matrixfunc.h"

int main() {
    // Объявление матрицы 10x10
    int matritsa[ROW][COL];
    char vybor;               // Переменная для выбора пункта меню
    char file[100];      // Имя файла для ввода данных
    
    // Инициализация матрицы нулями
    matrix(matritsa);
    
    // Основной цикл программы с меню
    do {
        // Вывод меню
        printf("a. постолбцовый ввод снизу вверх (из файла)\n");
        printf("b. предствление массива (матрица значений)\n");
        printf("c. индексы максимального и минимального значений\n");
        printf("d. сумма значений выше главной диагонали (включительно)\n");
        printf("e. выход\n");
        printf("выберите опцию: ");
        
        // Чтение выбора пользователя
        scanf(" %c", &vybor);
        
        // Обработка выбора пользователя
        switch(vybor) {
            case 'a':
                // Ввод матрицы из файла
                printf("введите имя файла: ");
                scanf("%s", file);
                snizuverh(matritsa, file);
                printf("матрица загружена из файла %s\n", file);
                break;
                
            case 'b':
                // Вывод матрицы с индексами
                printf("\nматрица %dx%d:\n", ROW, COL);
                indeks(matritsa);
                break;
                
            case 'c':
                {
                    // Объявление переменных для индексов минимального и максимального элементов
                    int rowMin, colMin, rowMax, colMax;
                    
                    // Поиск индексов минимального и максимального элементов
                    naytiIndeksyMinMax(matritsa, &rowMin, &colMin, &rowMax, &colMax);
                    
                    // Вывод результатов
                    printf("минимальный элемент: матрица[%d][%d] = %d\n", rowMin, colMin, matritsa[rowMin][colMin]);
                    printf("максимальный элемент: матрица[%d][%d] = %d\n", rowMax, colMax, matritsa[rowMax][colMax]);
                }
                break;
                
            case 'd':
                {
                    // Вычисление суммы элементов выше главной диагонали
                    int summa = summa(matritsa);
                    printf("сумма элементов выше главной диагонали (включительно): %d\n", summa);
                }
                break;
                
            case 'e':
                // Выход из программы
                printf("выход из программы.\n");
                break;
                
            default:
                // Обработка неверного выбора
                printf("неверный выбор, попробуйте снова.\n");
        }
    } while(vybor != 'e');  // Продолжаем цикл, пока пользователь не выберет выход
    
    return 0;  // Успешное завершение программы
}
