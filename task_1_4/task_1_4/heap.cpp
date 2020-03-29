//
//  heap.cpp
//  task_1_4
//
//  Created by Mac-HOME on 10.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "heap.hpp"

template<class T, class Compare>
BinominalHeap<T, Compare>::BinominalHeap(const Compare& cmp) {
    arr_capacity = 7;
    arr_size = 0;
    cmp_func = cmp;
    arr = new T[arr_capacity];
}

template<class T, class Compare>
BinominalHeap<T, Compare>::BinominalHeap(const T* data_arr, const int size, const Compare& cmp) {
    arr_capacity = size;
    arr_size = size;
    cmp_func = cmp;
    arr = new T[arr_capacity];
    std::copy(data_arr, data_arr + size, arr);
    build();
}

template<class T, class Compare>
BinominalHeap<T, Compare>::~BinominalHeap() {
    delete[] arr;
}

template<class T, class Compare>
void BinominalHeap<T, Compare>::push(const T& data) {
    if (isFull()) {
        extendArray();
    }
    
    arr[arr_size++] = data;
    shiftUp(arr_size - 1);
}

template<class T, class Compare>
T BinominalHeap<T, Compare>::pop() {
    assert(!isEmpty());
    
    int tmp = arr[0];
    arr[0] = arr[--arr_size];
    shiftDown(0);
    
    return tmp;
}

template<class T, class Compare>
const T& BinominalHeap<T, Compare>::top() const {
    assert(!isEmpty());
    
    return arr[0];
}

template<class T, class Compare>
void BinominalHeap<T, Compare>::extendArray() {
    arr_capacity *= 2;
    T* tmp = new T[arr_capacity];
    std::copy(arr, arr + arr_size, tmp);
    delete[] arr;
    arr = tmp;
}

template<class T, class Compare>
void BinominalHeap<T, Compare>::build() {
    for (int i = 0; i < arr_size / 2; ++i) {
        shiftDown(i);
    }
}

template<class T, class Compare>
void BinominalHeap<T, Compare>::shiftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (cmp_func(arr[parent], arr[index])) {
            return;
        }
        
        std::swap(arr[index], arr[parent]);
        index = parent;
    }
}

template<class T, class Compare>
void BinominalHeap<T, Compare>::shiftDown(int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    
    if (left < arr_size && cmp_func(arr[left], arr[largest])) {
        largest = left;
    }
    if (right < arr_size && cmp_func(arr[right], arr[largest])) {
        largest = right;
    }
    
    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        shiftDown(largest);
    }
}
