#include <iostream>

void countSort(int *a, int n) {
    int maxn = 0;
    for (int i = 0; i < n; ++i) { // ищем макс
        maxn = std::max(maxn, a[i]);
    }
    maxn += 1;
    int cnt[maxn], b[n]; // кол-во + итоговый
    for (int i = 0; i < maxn; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) { // насчитываем кол-во
        cnt[a[i]] += 1;
    }
    for (int i = 1; i < maxn; ++i) { // префик. суммы
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[a[i]] -= 1; // получаем индекс
        b[cnt[a[i]]] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
}