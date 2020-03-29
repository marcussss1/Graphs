//
//  main.cpp
//  task_1_1
//
//  Created by Mac-HOME on 09.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 В каждой задаче, где начальными данными является массив вначале
 вводится количество элементов, а затем и сами элементы массива.
 
 1_1. Даны два массива целых чисел одинаковой длины A[0..n-1] и B[0..n-1].
 Необходимо найти первую пару индексов i0 и j0, i0 ≤ j0, такую что
 A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i < n,0 <= j < n, i <= j}.
 
 Требования: Время работы - O(n).
 n ≤ 100000.
 */

#include <iostream>
#include <cassert>

void searchMaxPair(const int* A, const int* B, const int n, int& i0, int& j0);

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    assert(n >= 0);
    int* A = new int[n];
    int* B = new int[n];
    
    for (int i = 0, elem = 0; i < n; ++i) {
        std::cin >> elem;
        A[i] = elem;
    }
    
    for (int i = 0, elem = 0; i < n; ++i) {
        std::cin >> elem;
        B[i] = elem;
    }
    
    int i0 = 0, j0 = 0;
    searchMaxPair(A, B, n, i0, j0);
    
    std::cout << i0 << " " << j0;
    
    delete[] A;
    delete[] B;
    
    return 0;
}

void searchMaxPair(const int* A, const int* B, const int n, int& i0, int& j0) {
    assert(A && B && n >= 0);
    
    int i_max_A = 0;
    int max_sum = A[i_max_A] + B[0];
    i0 = 0;
    j0 = 0;
    
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i_max_A]) {
            i_max_A = i;
        }
        
        if (A[i_max_A] + B[i] > max_sum) {
            max_sum = A[i_max_A] + B[i];
            i0 = i_max_A;
            j0 = i;
        }
    }
}
