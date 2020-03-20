//
//  main.cpp
//  task_1_6
//
//  Created by Mac-HOME on 20.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Даны неотрицательные целые числа n,k и массив целых чисел из
 [0..10^9] размера n. Требуется найти k-ю порядковую статистику.
 т.е. напечатать число, которое бы стояло на позиции с индексом
 k (0..n-1) в отсортированном массиве.
 
 Реализуйте стратегию выбора опорного элемента “медиана трёх”.
 Функцию Partition реализуйте методом прохода двумя итераторами
 от конца массива к началу.
 */

#include <iostream>
#include <cassert>
#include <ctime>

template<class T>
class IsLessFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return (l < r);
    }
};

template<class T>
bool IsNoLess(const T& l, const T& r) {
    return (l >= r);
}

template<class T, class Compare = IsLessFunctor<T>>
int find_k_stat(T* arr, int n, int k, const Compare& cmp = Compare());

int main(int argc, const char * argv[]) {
    int n = 0, k = 0;
    std::cin >> n >> k;
    
    int* arr = new int[n];
    for (int i = 0, elem = 0; i < n; ++i) {
        std::cin >> elem;
        arr[i] = elem;
    }
    
    int k_stat = find_k_stat(arr, n, k, IsNoLess<int>);
    
    std::cout << k_stat;
    
    delete[] arr;
    
    return 0;
}

int calcMedianOfThree(const int* arr, const int l, const int r) {
    assert(arr && l >= 0 && r >= 0);
    
    std::srand(unsigned(std::time(0)));
    int count = 3;
    int positions[count];
    for (int i = 0; i < count; ++i) {
        positions[i] = l + std::rand() % (r - l + 1);
    }
    
    int mid_pos = -1;
    for (int i = 0; i < count && mid_pos == -1; ++i) {
        int one = arr[positions[i]];
        int two = arr[positions[(i + 1) % count]];
        int three = arr[positions[(i + 2) % count]];
        
        if (one >= two) {
            if (one <= three) {
                mid_pos = positions[i];
            }
        } else {
            if (one >= three) {
                mid_pos = positions[i];
            }
        }
    }
    
    return mid_pos;
}

template<class T, class Compare>
int partition(T* arr, int left, int right, const Compare& cmp_func) {
    assert(arr);
    
    int pivot_pos = calcMedianOfThree(arr, left, right);
    if (pivot_pos != left) {
        std::swap(arr[pivot_pos], arr[left]);
        pivot_pos = left;
    }
    
    int i = right;
    for (int j = right; j > left; --j) {
        if (cmp_func(arr[j], arr[pivot_pos])) {
            if (i != j) {
                std::swap(arr[j], arr[i]);
            }
            --i;
        }
    }
    
    if (pivot_pos != i) {
        std::swap(arr[pivot_pos], arr[i]);
    }
    
    return i;
}

template<class T, class Compare>
int find_k_stat(T* arr, int n, int k, const Compare& cmp) {
    assert(arr && k >= 0 && k < n);
    
    int left = 0;
    int right = n - 1;
    int pivot_pos = -1;
    
    while (pivot_pos != k) {
        pivot_pos = partition(arr, left, right, cmp);
        
        if (pivot_pos < k) {
            left = pivot_pos + 1;
        } else if (pivot_pos > k) {
            right = pivot_pos - 1;
        }
    }
    
    return arr[pivot_pos];
}
