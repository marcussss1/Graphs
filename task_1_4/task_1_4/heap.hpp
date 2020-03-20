//
//  heap.hpp
//  task_1_4
//
//  Created by Mac-HOME on 10.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <iostream>
#include <cassert>

template<class T>
class IsLessFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return (l < r);
    }
};

template<class T>
class IsGreaterFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return (l > r);
    }
};

template<class T, class Compare = IsGreaterFunctor<T>>
class BinominalHeap {
public:
    BinominalHeap(const Compare& cmp = Compare());
    ~BinominalHeap();
    
    void push(const T& data);
    T pop();
    T top() const;
    
    bool isEmpty() const { return (arr_size == 0); }
    int size() const { return arr_size; }
    
private:
    T* arr;
    int arr_capacity;
    int arr_size;
    Compare cmp_func;
    
    bool isFull() const { return (arr_size == arr_capacity); }
    void extendArray();
    
    void shiftUp(int index);
    void shiftDown(int index);
};

#endif /* heap_hpp */
