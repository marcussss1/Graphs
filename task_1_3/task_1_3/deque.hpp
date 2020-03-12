//
//  deque.hpp
//  task_1_3
//
//  Created by Mac-HOME on 10.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#ifndef deque_hpp
#define deque_hpp

#include <cassert>

template<class T>
class Deque {
public:
    Deque();
    ~Deque();
    
    void push_front(const T& data);
    T pop_front();
    void push_back(const T& data);
    T pop_back();
    
    bool isEmpty() const { return (size == 0); }
    
private:
    T* buffer;
    int capacity;
    int size;
    int front;
    int back;
    
    bool isFull() const { return (size == capacity); }
    void extendBuffer();
};

#endif /* deque_hpp */
