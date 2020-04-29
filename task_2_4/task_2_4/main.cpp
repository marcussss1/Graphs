//
//  main.cpp
//  task_2_4
//
//  Created by Mac-HOME on 29.04.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Порядковые статистики. Дано число N и N строк. Каждая
 строка содержит команду добавления или удаления
 натуральных чисел, а также запрос на получение k-ой
 порядковой статистики. Команда добавления числа A
 задается положительным числом A, команда удаления числа A
 задается отрицательным числом “-A”. Запрос на получение
 k-ой порядковой статистики задается числом k.
 
 Требования: скорость выполнения запроса - O(log n).
 */

#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;

template<class T>
class DefaultAVLFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return l < r;
    }
};

template<class T>
struct AVLTreeNode {
    AVLTreeNode* left;
    AVLTreeNode* right;
    T key;
    unsigned int height;
    unsigned int number;
    
    AVLTreeNode() :
        left(nullptr),
        right(nullptr),
        height(1),
        number(1) {}
    AVLTreeNode(const T& _key) :
        left(nullptr),
        right(nullptr),
        height(1),
        number(1),
        key(_key) {}
};

template<class T, class Compare = DefaultAVLFunctor<T>>
class AVLTree {
public:
    AVLTree();
    AVLTree(const Compare& cmp);
    AVLTree(const AVLTree& tree) = delete;
    AVLTree& operator= (const AVLTree& tree) = delete;
    ~AVLTree();
    
    void add(const T& key);
    void remove(const T& key);
    const T& get_k_stat(int k) const;
    
private:
    AVLTreeNode<T>* add_node(AVLTreeNode<T>* node, const T& key);
    AVLTreeNode<T>* remove_node(AVLTreeNode<T>* node, const T& key);
    void remove_all(AVLTreeNode<T>* node);
    
    AVLTreeNode<T>* rotate_left(AVLTreeNode<T>* node);
    AVLTreeNode<T>* rotate_right(AVLTreeNode<T>* node);
    
    AVLTreeNode<T>* remove_min(AVLTreeNode<T>* node);
    AVLTreeNode<T>* remove_max(AVLTreeNode<T>* node);
    
    unsigned int height(AVLTreeNode<T>* node);
    void fix_height(AVLTreeNode<T>* node);
    int balance_factor(AVLTreeNode<T>* node);
    AVLTreeNode<T>* balance(AVLTreeNode<T>* node);
    
    AVLTreeNode<T>* root;
    Compare cmp_func;
};

template<class T, class Compare>
AVLTree<T, Compare>::AVLTree() :
    root(nullptr) {}

template<class T, class Compare>
AVLTree<T, Compare>::AVLTree(const Compare& cmp) :
    root(nullptr),
    cmp_func(cmp) {}

template<class T, class Compare>
AVLTree<T, Compare>::~AVLTree() {
    remove_all(root);
}

template<class T, class Compare>
void AVLTree<T, Compare>::add(const T& key) {
    add_node(root, key);
}

template<class T, class Compare>
void AVLTree<T, Compare>::remove(const T& key) {
    remove_node(root, key);
}

template<class T, class Compare>
const T& AVLTree<T, Compare>::get_k_stat(int k) const {
    
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::
add_node(AVLTreeNode<T>* node, const T& key) {
    if (!node) {
        return new AVLTreeNode<T>(key);
    }
    if (key < node->key) {
        node->left = add_node(node->left, key);
    } else {
        node->right = add_node(node->right, key);
    }
    return balance(node);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::
remove_node(AVLTreeNode<T>* node, const T& key) {
    if (!node) {
        return nullptr;
    }
    
    T cur_node = node->key;
    if (key < cur_node) {
        node->left = remove_node(node->left, key);
    } else if (key != cur_node) {
        node->right = remove_node(node->right, key);
    } else {
        AVLTreeNode<T>* left = node->left;
        AVLTreeNode<T>* right = node->right;
        delete node;
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        if (height(left) > height(right)) {
            node = remove_max(left);
        } else {
            node = remove_min(right);
        }
    }
    return balance(node);
}

template<class T, class Compare>
void AVLTree<T, Compare>::remove_all(AVLTreeNode<T>* node) {
    if (node) {
        remove_all(node->left);
        remove_all(node->right);
        delete(node);
    }
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::rotate_left(AVLTreeNode<T>* node) {
    AVLTreeNode<T>* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    fix_height(node);
    fix_height(tmp);
    return tmp;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::rotate_right(AVLTreeNode<T>* node) {
    AVLTreeNode<T>* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    fix_height(node);
    fix_height(tmp);
    return tmp;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::remove_min(AVLTreeNode<T>* node) {
    AVLTreeNode<T>* cur_node = node->left;
    if (!cur_node) {
        return node;
    }
    
    AVLTreeNode<T>* prev_node = node;
    while (cur_node->left) {
        prev_node = cur_node;
        cur_node = cur_node->left;
    }
    prev_node->left = cur_node->right;
    return cur_node;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::remove_max(AVLTreeNode<T>* node) {
    AVLTreeNode<T>* cur_node = node->right;
    if (!cur_node) {
        return node;
    }
    
    AVLTreeNode<T>* prev_node = node;
    while (cur_node->right) {
        prev_node = cur_node;
        cur_node = cur_node->right;
    }
    prev_node->right = cur_node->left;
    return cur_node;
}

template<class T, class Compare>
unsigned int AVLTree<T, Compare>::height(AVLTreeNode<T>* node) {
    return node ? node->height : 0;
}

template<class T, class Compare>
void AVLTree<T, Compare>::fix_height(AVLTreeNode<T>* node) {
    unsigned int hl = height(node->left);
    unsigned int hr = height(node->right);
    node->height = ((hl > hr) ? hl : hr) + 1;
}

template<class T, class Compare>
int AVLTree<T, Compare>::balance_factor(AVLTreeNode<T>* node) {
    return height(node->right) - height(node->left);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::balance(AVLTreeNode<T>* node) {
    fix_height(node);
    if (balance_factor(node) == 2) {
        if (balance_factor(node->right) < 0) {
            node->right = rotate_right(node->right);
        }
        node =  rotate_left(node);
    } else if (balance_factor(node) == -2) {
        if (balance_factor(node->right) > 0) {
            node->left = rotate_left(node->left);
        }
        node =  rotate_right(node);
    }
    return node;
}

int main(int argc, const char * argv[]) {
    AVLTree<int, DefaultAVLFunctor<int>> tree;
    int n = 0;
    cin >> n;
    
    for (int i = 0, num = 0, k = 0; i < n; ++i) {
        cin >> num >> k;
        if (num >= 0) {
            tree.add(num);
        } else {
            tree.remove(num);
        }
    }
    
    return 0;
}
