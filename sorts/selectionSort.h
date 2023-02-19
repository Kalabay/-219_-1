#include <iostream>

void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int index_where_min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[index_where_min] > a[j]) { // поиск минимума из неотсорт
                index_where_min = j;
            }
        }
        std::swap(a[i], a[index_where_min]); // вставка минимума
    }
}