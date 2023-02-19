#include <iostream>

void bubbleSortIverson12(int *a, int n) {
    int t = n - 1;
    while (t) { // если уже отсорт, то выходим
        int t_new = 0;
        for (int i = 0; i < t; ++i) { // нет смысла смотреть дальше ласт обмена
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                t_new = i;
            }
        }
        t = t_new;
    }
}