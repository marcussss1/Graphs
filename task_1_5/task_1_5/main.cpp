//
//  main.cpp
//  task_1_5
//
//  Created by Mac-HOME on 20.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 На числовой прямой окрасили N отрезков. Известны координаты левого и правого
 концов каждого отрезка (Li и Ri). Найти длину окрашенной части числовой прямой.
 */

#include <iostream>
#include <cassert>

template<class T>
class IsLessFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return (l < r);
    }
};

template <class T>
struct Line {
    Line() : left_edge(0), right_edge(0) {}
    Line(const T& l, const T& r) : left_edge(l), right_edge(r) {}
    
    T left_edge;
    T right_edge;
};

template<class T>
bool IsLessLineEdge(const Line<T>& l, const Line<T>& r) {
    return (l.left_edge <= r.left_edge);
}

template<class T, class Compare = IsLessFunctor<T>>
void mergeSort(T* arr, const int size, const Compare& cmp = Compare());

int main(int argc, const char * argv[]) {
    int n = 0;
    std::cin >> n;
    
    assert(n >= 0);
    Line<int>* lines = new Line<int>[n];
    for (int i = 0, li = 0, ri = 0; i < n; ++i) {
        std::cin >> li >> ri;
        lines[i] = Line<int>(li, ri);
    }
    
    mergeSort(lines, n, IsLessLineEdge<int>);
    
    int colored_part_lenght = 0;
    int cur_left_edge = lines[0].left_edge;
    
    for (int i = 0; i < n; ++i) {
        if (lines[i].right_edge > cur_left_edge) {
            if (lines[i].left_edge > cur_left_edge) {
                cur_left_edge = lines[i].left_edge;
            }
            
            colored_part_lenght += lines[i].right_edge - cur_left_edge;
            cur_left_edge = lines[i].right_edge;
        }
    }
    
    std::cout << colored_part_lenght;
    
    delete[] lines;
    
    return 0;
}

template<class T, class Compare>
void merge_arrays(T* merged, const T* l_arr, const int l_size,
           const T* r_arr, const int r_size, const Compare& cmp_func) {
    assert(merged && l_arr && r_arr);
    
    int i = 0;
    int l_i = 0;
    int r_i = 0;
    
    while (l_i < l_size && r_i < r_size) {
        if (cmp_func(l_arr[l_i], r_arr[r_i])) {
            merged[i++] = l_arr[l_i++];
        } else {
            merged[i++] = r_arr[r_i++];
        }
    }
    
    if (l_i < l_size) {
        std::copy(l_arr + l_i, l_arr + l_size, merged + i);
    }
    if (r_i < r_size) {
        std::copy(r_arr + r_i, r_arr + r_size, merged + i);
    }
}

template<class T, class Compare>
void mergeSort(T* arr, const int size, const Compare& cmp) {
    assert(arr);
    if (size <= 1) {
        return;
    }
    
    int l_size = size / 2;
    int r_size = size - l_size;
    
    mergeSort(arr, l_size, cmp);
    mergeSort(arr + l_size, r_size, cmp);
    
    T* merged = new T[size];
    merge_arrays(merged, arr, l_size, arr + l_size, r_size, cmp);
    std::copy(merged, merged + size, arr);
    delete[] merged;
}
