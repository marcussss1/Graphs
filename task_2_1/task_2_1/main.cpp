//
//  main.cpp
//  task_2_1
//
//  Created by Mac-HOME on 27.04.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

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
    if (keys_count * 3 > 2 * table.size()) {
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
    table[cell_to_add]->key = key;
    table[cell_to_add]->make_full();
    return true;
}

template<class T, class H>
bool HashTable<T, H>::remove(const T& key) {}

template<class T, class H>
unsigned int HashTable<T, H>::calc_next_index(int hash, int iter) const {
    return (hash + iter + 1) % table.size();
}

template<class T, class H>
void HashTable<T, H>::grow() {}

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

    while( cin >> operation >> word ) {
        if( operation == '+' )
            cout << (table.add( word ) ? "OK" : "FAIL") << "\n";
        else if( operation == '-' )
            cout << (table.remove( word ) ? "OK" : "FAIL") << "\n";
        else if( operation == '?' )
            cout << (table.has( word ) ? "OK" : "FAIL") << "\n";
        else
            assert( false );
    }
    
    return 0;
}
