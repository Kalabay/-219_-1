#include <iostream>

void insertionSort(int *a, int n) {
    for (int j = 1; j < n; ++j) {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key) { // ищем место для вставки
            a[i + 1] = a[i]; // двигаем вправо
            i -= 1;
        }
        a[i + 1] = key; // сама вставка
    }
}