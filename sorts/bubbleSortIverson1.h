#include <iostream>
#include <vector>

void bubbleSortIverson1(int *a, int n) {
    bool check = true;
    int j = 0;
    while (check) { // если уже отсорт, то выходим
        check = false;
        for (int i = 0; i < n - 1 - j; ++i) { // нет смысла смотреть после n - 1 - j
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                check = true;
            }
        }
        ++j;
    }
}
