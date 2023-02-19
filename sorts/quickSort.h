#include <iostream>

int partition(int *a, int left, int right) {
    int pivot = a[left]; // первый опорный
    int i = left;
    int j = right;
    // для того, чтобы меньше слева, больше справа
    while (i <= j) { // метод 2 указателей
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(a[i++], a[j--]);
    }
    return j;
}

void quickSort(int *a, int left, int right) {
    if (left < right) {
        int q = partition(a, left, right);
        quickSort(a, left, q); // сорт слева
        quickSort(a, q + 1, right); // сорт справа
    }
}

void callQuickSort(int *a, int n) {
    quickSort(a, 0, n - 1);
}