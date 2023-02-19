#include <iostream>

void shellSoortS(int *a, int n) {
    for (int d = n / 2; d != 0; d /= 2) { // уменьшаем в 2 раза d
        for (int i = d; i < n; ++i) {
            for (int j = i; j >= d && a[j] < a[j - d]; j -= d) { // группы на расстоянии d
                std::swap(a[j], a[j - d]);
            }
        }
    }
}