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
        printf("\n=== MENU ===\n");
        printf("a. Postolbtsovyy vvod snizu-vverh (iz faila)\n");
        printf("b. Predstavlenie massiva (matritsa znacheniy)\n");
        printf("c. Indeksy maksimalnogo i minimalnogo znacheniy\n");
        printf("d. Summa znacheniy vyshe glavnoy diagonali (vklyuchitelno)\n");
        printf("e. Vykhod\n");
        printf("Vyberite opciyu: ");
        
        // Чтение выбора пользователя
        scanf(" %c", &vybor);
        
        // Обработка выбора пользователя
        switch(vybor) {
            case 'a':
                // Ввод матрицы из файла
                printf("Vvedite imya faila: ");
                scanf("%s", file);
                snizuverh(matritsa, file);
                printf("Matritsa zagruzhena iz faila %s\n", file);
                break;
                
            case 'b':
                // Вывод матрицы с индексами
                printf("\nMatritsa %dx%d:\n", ROW, COL);
                indeks(matritsa);
                break;
                
            case 'c':
                {
                    // Объявление переменных для индексов минимального и максимального элементов
                    int rowMin, colMin, rowMax, colMax;
                    
                    // Поиск индексов минимального и максимального элементов
                    naytiIndeksyMinMax(matritsa, &rowMin, &colMin, &rowMax, &colMax);
                    
                    // Вывод результатов
                    printf("Minimalnyy element: matritsa[%d][%d] = %d\n", rowMin, colMin, matritsa[rowMin][colMin]);
                    printf("Maksimalnyy element: matritsa[%d][%d] = %d\n", rowMax, colMax, matritsa[rowMax][colMax]);
                }
                break;
                
            case 'd':
                {
                    // Вычисление суммы элементов выше главной диагонали
                    int summa = summa(matritsa);
                    printf("Summa elementov vyshe glavnoy diagonali (vklyuchitelno): %d\n", summa);
                }
                break;
                
            case 'e':
                // Выход из программы
                printf("Vykhod iz programmy.\n");
                break;
                
            default:
                // Обработка неверного выбора
                printf("Nevernyy vybor. Poprobuyte snova.\n");
        }
    } while(vybor != 'e');  // Продолжаем цикл, пока пользователь не выберет выход
    
    return 0;  // Успешное завершение программы
}
