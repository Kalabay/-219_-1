#include <iostream>

void bubbleSort(int *a, int n) {
    for (int j = 0; j < n - 1; ++j) { // n - 1 точно хватает
        for (int i = 0; i < n - 1 - j; ++i) { // нет смысла смотреть после n - 1 - j
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
            }
        }
    }
}