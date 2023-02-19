#include <iostream>

void radixSort(int *a, int n) {
    int m = 256;
    int ans[n];
    for (int i = 0; i < n; ++i) {
        ans[i] = i;
    }
    for (int j = 0; j < 7; ++j) {
        int cnt[m];
        for (int i = 0; i < m; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int now = (m - 1) & ((a[ans[i]]) >> (8 * j)); // получаем число для сорта
            cnt[now] += 1;
        }
        int ans_new[n]; // сортировка подсчётом
        int cnt_sum = 0;
        for (int i = 0; i < m; ++i) {
            int prev = cnt_sum;
            cnt_sum += cnt[i];
            cnt[i] = prev;
        }
        for (int i = 0; i < n; ++i) {
            int now = (m - 1) & ((a[ans[i]]) >> (8 * j)); // получаем число для сорта
            int ind = cnt[now];
            ans_new[ind] = ans[i];
            cnt[now] += 1;
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = ans_new[i];
        }
    }
    int result[n];
    for (int i = 0; i < n; ++i) {
        result[i] = a[ans[i]];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = result[i];
    }
}