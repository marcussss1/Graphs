//
//  main.cpp
//  task_2_1
//
//  Created by Mac-HOME on 27.04.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//


/*
 Реализуйте структуру данных типа “множество строк” на основе динамической
 хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из
 строчных латинских букв.
 
 Хеш-функция строки должна быть реализована с помощью вычисления значения
 многочлена методом Горнера.

 Структура данных должна поддерживать операции добавления строки в множество,
 удаления строки из множества и проверки принадлежности данной строки множеству.

 Для разрешения коллизий используйте квадратичное пробирование. i-ая проба
 g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.
*/

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using std::cout;
using std::cin;
using std::vector;
using std::string;

template<class T>
struct HashTableCell {
    enum StateType {
        EMPTY,
        FULL,
        DELETED
    };
    
    T key;
    StateType state;
    
    HashTableCell() :
        state(EMPTY) {}
    HashTableCell(const T& _key) :
        key(_key),
        state(FULL) {}
    
    bool is_full() const { return state == FULL; }
    bool is_empty() const { return state == EMPTY; }
    void make_full() { state = FULL; }
    void make_del() { state = DELETED; }
};

template<class T, class H>
class HashTable {
public:
    HashTable(int init_size = 8, const H& hasher = H());
    
    bool has(const T& key) const;
    bool add(const T& key);
    bool remove(const T& key);
    
private:
    unsigned int calc_next_index(int hash, int iter) const;
    void grow();
    
    H hasher;
    vector<HashTableCell<T>> table;
    unsigned int keys_count;
};

template<class T, class H>
HashTable<T, H>::HashTable(int init_size, const H& _hasher) :
    table(init_size),
    hasher(_hasher),
    keys_count(0) {}

template<class T, class H>
bool HashTable<T, H>::has(const T& key) const {
    unsigned int hash = hasher(key) % table.size();
    
    for (int i = 0; i < table.size(); ++i) {
        if (table[hash].is_full() && table[hash].key == key) {
            return true;
        } else if (table[hash].is_empty()) {
            break;
        }
        hash = calc_next_index(hash, i);
    }
    return false;
}

template<class T, class H>
bool HashTable<T, H>::add(const T& key) {
    if (keys_count * 4 > 3 * table.size()) {
        grow();
    }
    
    unsigned int hash = hasher(key) % table.size();
    HashTableCell<T>* cell_to_add = nullptr;
    
    for (int i = 0; i < table.size(); ++i) {
        if (table[hash].is_full()) {
            if (table[hash].key == key) {
                return false;
            }
        } else {
            // deleted or empty
            if (cell_to_add == nullptr) {
                cell_to_add = &table[hash];
            }
            if (table[hash].is_empty()) {
                break;
            }
        }
        hash = calc_next_index(hash, i);
    }
    cell_to_add->key = key;
    cell_to_add->make_full();
    ++keys_count;
    return true;
}

template<class T, class H>
bool HashTable<T, H>::remove(const T& key) {
    unsigned int hash = hasher(key) % table.size();
    
    for (int i = 0; i < table.size(); ++i) {
        if (table[hash].is_full() && table[hash].key == key) {
            table[hash].make_del();
            --keys_count;
            return true;
        } else if (table[hash].is_empty()) {
            break;
        }
        hash = calc_next_index(hash, i);
    }
    return false;
}

template<class T, class H>
unsigned int HashTable<T, H>::calc_next_index(int hash, int iter) const {
    return (hash + iter + 1) % table.size();
}

template<class T, class H>
void HashTable<T, H>::grow() {
    vector<HashTableCell<T>> prev_table = table;
    table = vector<HashTableCell<T>>(table.size() * 2);
    
    for (int i = 0; i < prev_table.size(); ++i) {
        if (prev_table[i].is_full()) {
            add(prev_table[i].key);
        }
    }
}

struct StringHasher {
    unsigned int operator()(const string& key) const {
        const int a = 113;
        unsigned int hash = 0;
        for(int i = 0; i < key.size(); ++i) {
            hash = hash * a + key[i];
        }
        return hash;
    }
};

int main(int argc, const char * argv[]) {
    HashTable<string, StringHasher> table;
    char operation = 0;
    string word;

    while(cin >> operation >> word) {
        if(operation == '+')
            cout << (table.add(word) ? "OK" : "FAIL") << "\n";
        else if(operation == '-')
            cout << (table.remove(word) ? "OK" : "FAIL") << "\n";
        else if(operation == '?')
            cout << (table.has(word) ? "OK" : "FAIL") << "\n";
        else
            assert(false);
    }
    
    return 0;
}
