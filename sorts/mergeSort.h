#include <iostream>

void mergeSort(int *a, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);  // сорт слева
    mergeSort(a, mid + 1, r);  // сорт справа
    int result[r - l + 1]; // для мёрджа
    int i = l;
    int j = mid + 1;
    int p = 0;
    while (i <= mid || j <= r) { // сам мёрдж, i, j - условно указатели на левый и правый массив
        if (i > mid) {
            result[p] = a[j];
            ++j;
        } else if (j > r) {
            result[p] = a[i];
            ++i;
        } else if (a[i] < a[j]) {
            result[p] = a[j];
            ++j;
        } else {
            result[p] = a[i];
            ++i;
        }
        ++p;
    }
    for (int q = 0; q < r - l + 1; ++q) { // запись результата
        a[q + l] = result[q];
    }
}

void callMergeSort(int *a, int n) {
    mergeSort(a, 0, n - 1);
}