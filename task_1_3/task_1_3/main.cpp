//
//  main.cpp
//  task_1_3
//
//  Created by Mac-HOME on 10.03.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды push* и pop*.
 Формат входных данных.
 В первой строке количество команд n. n ≤ 1000000.
 Каждая команда задаётся как 2 целых числа: a b.
 a = 1 - push front
 a = 2 - pop front
 a = 3 - push back
 a = 4 - pop back
 Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
 Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
 Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.
 Формат выходных данных.
 Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

 
 Реализовать дек с динамическим зацикленным буфером.
 
 */



#include <iostream>
#include <cassert>

#include "deque.cpp"


int main(int argc, const char * argv[]) {
    int n = 0;
    std::cin >> n;
    
    Deque<int> deque;
    
    bool result = true;
    for (int i = 0, cmd = 0, data = 0; i < n && result; ++i) {
        std::cin >> cmd >> data;
        
        switch(cmd) {
            case 1:
                deque.push_front(data);
                break;
            case 2:
                if (deque.isEmpty()) {
                    result = (data == -1);
                } else {
                    result = (data == deque.pop_front());
                }
                break;
            case 3:
                deque.push_back(data);
                break;
            case 4:
                if (deque.isEmpty()) {
                    result = (data == -1);
                } else {
                    result = (data == deque.pop_back());
                }
                break;
            default:
                assert(false);
        }
    }
    
    std::cout << (result ? "YES" : "NO");
    
    return 0;
}
