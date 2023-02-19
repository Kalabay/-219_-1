#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <fstream>
#include <vector>

#include "bubbleSort.h"
#include "bubbleSortIverson1.h"
#include "bubbleSortIverson12.h"
#include "countSort.h"
#include "insertionSort.h"
#include "insertionSortBin.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "shellSortC.h"
#include "shellSortS.h"
#include "heapSort.h"

// для 1 графика для 1 сортировки + 4 линии
std::vector<std::vector<long long> > calc_time_for_steps(std::function<void(int *, int)> sort_algo, int n, int step, int *ptr5, int *ptr4000, int *ptr_almost, int *ptr_anti) {
    std::vector<std::vector<long long > > result(4, std::vector<long long>(0));
    for (int n_now = n; n_now >= step; n_now -= step) {
        long long res_now = 0;
        for (int cnt = 0; cnt < 50; ++cnt) { // массив x = 0...5
            int a5[n_now];
            for (int i = 0; i < n_now; ++i) {
                a5[i] = ptr5[i];
            }
            auto start = std::chrono::high_resolution_clock::now();
            sort_algo(a5, n_now);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long nano =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            res_now += nano;
        }
        res_now /= 50;
        result[0].push_back(res_now);

        res_now = 0;
        for (int cnt = 0; cnt < 50; ++cnt) { // массив x = 0...4000
            int a4000[n_now];
            for (int i = 0; i < n_now; ++i) {
                a4000[i] = ptr4000[i];
            }
            auto start = std::chrono::high_resolution_clock::now();
            sort_algo(a4000, n_now);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long nano =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            res_now += nano;
        }
        res_now /= 50;
        result[1].push_back(res_now);

        res_now = 0;
        for (int cnt = 0; cnt < 50; ++cnt) { // почти сорт массив
            int a_almost[n_now];
            for (int i = 0; i < n_now; ++i) {
                a_almost[i] = ptr_almost[i];
            }
            auto start = std::chrono::high_resolution_clock::now();
            sort_algo(a_almost, n_now);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long nano =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            res_now += nano;
        }
        res_now /= 50;
        result[2].push_back(res_now);

        res_now = 0;
        for (int cnt = 0; cnt < 50; ++cnt) { // reverse массив
            int a_anti[n_now];
            for (int i = 0; i < n_now; ++i) {
                a_anti[n_now - 1 - i] = ptr_anti[4100 - 1 - i];
            }
            auto start = std::chrono::high_resolution_clock::now();
            sort_algo(a_anti, n_now);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long nano =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            res_now += nano;
        }
        res_now /= 50;
        result[3].push_back(res_now);
    }
    for (int i = 0; i < 4; ++i) {
        std::reverse(result[i].begin(), result[i].end());
    }
    return result;
}

int main() {
    std::ofstream fout("result.csv");
    fout << "type_array" << "," << "type_sort" << "," << "n" << "," << "time" << '\n';
    // классный рандом
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    // массив 0...5
    int len = 4100;
    int a5[len];
    for (int i = 0; i < len; ++i) {
        a5[i] = rng() % 6;
    }

    // массив 0...4000
    int a4000[len];
    for (int i = 0; i < len; ++i) {
        a4000[i] = rng() % 4001;
    }

    // почти отсорт массив
    int a_almost90[len];
    for (int i = 0; i < len; ++i) {
        a_almost90[i] = i + 1;
    }
    for (int i = 0; i < 41; ++i) {
        int i1 = rng() % len;
        int i2 = rng() % len;
        std::swap(a_almost90[i1], a_almost90[i2]);
    }

    // убыв. массив
    int a_anti[len];
    for (int i = 0; i < len; ++i) {
        a_anti[i] = len - i;
    }

    // все виды массивов и шагов

    std::vector<std::string> types300 = {"50-300 step=50 x = 0...5", "50-300 step=50 x = 0...4000",
                                         "50-300 step=50 almost (+- 90% sort)", "50-300 step=50 reverse"};
    std::vector<std::string> types4000 = {"100-4000 step=100 x = 0...5", "100-4000 step=100 x = 0...4000",
                                          "100-4000 step=100 almost (+- 90% sort)", "100-4000 step=100 reverse"};


    // все сортировки

    std::vector<std::function<void(int *, int)> > functions = {selectionSort, bubbleSort, bubbleSortIverson1,
                                                               bubbleSortIverson12, insertionSort, insertionSortBin,
                                                               countSort, radixSort, callMergeSort, callQuickSort,
                                                               heapSort, shellSoortC, shellSoortS};



    // все имена сортировок

    std::vector<std::string> functions_names = {"selectionSort", "bubbleSort", "bubbleSortIverson1",
                                                "bubbleSortIverson12", "insertionSort", "insertionSortBin",
                                                "countSort", "radixSort", "mergeSort", "quickSort",
                                                "heapSort", "shellSoortCiura", "shellSoortShell"};

    // все графики, где для каждой сортировки по 4 линии

    for (int q = 0; q < 13; ++q) {
        auto result = calc_time_for_steps(functions[q], 300, 50,
                                          a5, a4000, a_almost90, a_anti);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                fout << types300[i] << "," << functions_names[q] << "," << (j + 1) * 50 << "," << result[i][j] << '\n';
            }
        }

        result = calc_time_for_steps(functions[q], 4100, 100,
                                     a5, a4000, a_almost90, a_anti);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                fout << types4000[i] << "," << functions_names[q] << "," << (j + 1) * 100 << "," << result[i][j] << '\n';
            }
        }
    }

    return 0;
}
