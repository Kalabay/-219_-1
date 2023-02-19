#include <iostream>

void shellSoortC(int *a, int n) {
    int c[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750}; // последовательность Циура
    for (int q = 8; q >= 0; --q) {
        int d = c[q];
        for (int i = d; i < n; ++i) {
            for (int j = i; j >= d && a[j] < a[j - d]; j -= d) { // группы на расстоянии d
                std::swap(a[j], a[j - d]);
            }
        }
    }
}