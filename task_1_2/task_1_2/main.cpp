//
//  main.cpp
//  task_1_2
//
//  Created by Mac-HOME on 09.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 2_4. Дан отсортированный массив различных целых чисел A[0..n-1] и массив
 целых чисел B[0..m-1]. Для каждого элемента массива B[i] найдите
 минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
 
 Требования: Время работы поиска для каждого элемента B[i]: O(log(k)).
 */

#include <iostream>
#include <cassert>

int findElemClosestByValue(const int* A, const int n_A, const int value);

int main(int argc, const char * argv[]) {
    int n_A;
    std::cin >> n_A;
    
    assert(n_A >= 0);
    int* A = new int[n_A];
    for (int i = 0, elem = 0; i < n_A; ++i) {
        std::cin >> elem;
        A[i] = elem;
    }
    
    int n_B;
    std::cin >> n_B;
    
    assert(n_B >= 0);
    int* B = new int[n_B];
    for (int i = 0, elem = 0; i < n_B; ++i) {
        std::cin >> elem;
        B[i] = elem;
    }
    
    for (int i = 0; i < n_B; ++i) {
        int minInd = findElemClosestByValue(A, n_A, B[i]);
        std::cout << minInd << " ";
    }
    
    delete[] A;
    delete[] B;
    
    return 0;
}

int binarySearch(const int* A, int left, int right, const int value) {
    assert(A && left >= 0);
    
    while (left + 1 < right) {
        int mid = left + ((right - left) >> 1);
        
        if (A[mid] < value) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    return (value - A[left] <= A[right] - value) ? left : right;
}

int findElemClosestByValue(const int* A, const int n_A, const int value) {
    assert(A && n_A >= 0);
    
    int left = 0, right = 0, gap = 1;
    
    while (right < n_A && A[right] < value) {
        left = right;
        gap  = gap << 1;
        right = left + gap;
    }
    
    if (right >= n_A) {
        right = n_A - 1;
    }
    
    int minInd = binarySearch(A, left, right, value);
    
    return minInd;
}
