cmake_minimum_required(VERSION 3.17)
project(sorts)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorts main.cpp bubbleSort.h bubbleSortIverson1.h bubbleSortIverson12.h countSort.h insertionSort.h heapSort.h insertionSortBin.h quickSort.h radixSort.h selectionSort.h shellSortC.h shellSortS.h mergeSort.h)