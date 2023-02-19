#include <iostream>
#include <vector>

template <class ValueType> // просто класс кучи из контеста
class Heap {
public:
    Heap() {
        heap = {};
    }

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        while (begin != end) {
            insert(*begin);
            ++begin;
        }
    }

    Heap(std::initializer_list<ValueType> a) {
        for (ValueType elem : a) {
            insert(elem);
        }
    }

    Heap(const Heap &a) {
        heap = a.heap;
    }

    Heap &operator=(const Heap &a) {
        heap = a.heap;
        return *this;
    }

    Heap(Heap &&a) {
        heap = std::move(a.heap);
    }

    Heap &operator=(Heap &&a) {
        heap = std::move(a.heap);
        return *this;
    }

    size_t size() const {
        return heap.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void rebalanceDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        while (left < size()) {
            if (right < size()) {
                if (heap[index] > heap[left] || heap[index] > heap[right]) {
                    if (heap[right] < heap[left]) {
                        std::swap(heap[index], heap[right]);
                        index = right;
                    } else {
                        std::swap(heap[index], heap[left]);
                        index = left;
                    }
                } else {
                    return;
                }
            } else if (heap[index] > heap[left]) {
                std::swap(heap[index], heap[left]);
                index = left;
            } else {
                return;
            }
            left = 2 * index + 1;
            right = 2 * index + 2;
        }
    }

    void rebalanceUp(int index) {
        int prev = (index - 1) / 2;
        while (prev >= 0 && heap[prev] > heap[index]) {
            std::swap(heap[prev], heap[index]);
            index = prev;
            prev = (index - 1) / 2;
        }
    }

    void insert(const ValueType &x) {
        heap.push_back(x);
        rebalanceUp(heap.size() - 1);
    }

    ValueType extract() {
        ValueType res = heap[0];
        heap[0] = heap[size() - 1];
        heap.pop_back();
        rebalanceDown(0);
        return res;
    }

    std::vector<ValueType> heap;
};

void heapSort(int *a, int n) {
    Heap<int> heap;
    for (int i = 0; i < n; ++i) {
        heap.insert(a[i]); // добавляем в кучу
    }
    for (int i = 0; i < n; ++i) {
        a[i] = heap.extract(); // вытаскиваем минимум из корня
    }
}