#include <iostream>

void insertionSortBin(int *a, int n) {
    for (int j = 1; j < n; ++j) {
        int key = a[j];
        int left = -1;
        int right = j;
        while (right - left > 1) { // бинпоиск для поиска места для вставки
            int mid = (left + right);
            if (a[mid] > key) {
                right = mid;
            } else {
                left = mid;
            }
        }
        for (int i = j; i > right; --i) { // сама вставка
            std::swap(a[i], a[i - 1]);
        }
    }
}