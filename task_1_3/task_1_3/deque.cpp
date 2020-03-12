//
//  deque.cpp
//  task_1_3
//
//  Created by Mac-HOME on 10.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include "deque.hpp"

template<class T>
Deque<T>::Deque() {
    size = 0;
    front = -1;
    back = 0;
    
    capacity = 7;
    buffer = new T[capacity];
}

template<class T>
Deque<T>::~Deque() {
    delete[] buffer;
}

template<class T>
void Deque<T>::push_front(const T& data) {
    if (isFull()) {
        extendBuffer();
    }
    
    if (front == -1) {
        front = capacity - 1;
    }
    
    ++size;
    buffer[front--] = data;
}

template<class T>
T Deque<T>::pop_front() {
    assert(!isEmpty());
    
    --size;
    return buffer[++front];
}

template<class T>
void Deque<T>::push_back(const T& data) {
    if (isFull()) {
        extendBuffer();
    }
    
    if (back == capacity) {
        back = 0;
    }
    
    ++size;
    buffer[back++] = data;
}

template<class T>
T Deque<T>::pop_back() {
    assert(!isEmpty());
    
    --size;
    return buffer[--back];
}

template<class T>
void Deque<T>::extendBuffer() {
    capacity *= 2;
    T* tmp = new T[capacity];
    
    int i_tmp = 0;
    
    for (int i = ++front; i < size; ++i) {
        tmp[i_tmp++] = buffer[i];
    }
    
    if (back <= front) {
        for (int i = 0; i < back; ++i) {
            tmp[i_tmp++] = buffer[i];
        }
    }
    
    front = -1;
    back = size;
    
    delete[] buffer;
    buffer = tmp;
}



