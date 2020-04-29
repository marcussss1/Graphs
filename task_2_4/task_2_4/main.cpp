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
    unsigned int rank;
    
    AVLTreeNode() :
        left(nullptr),
        right(nullptr),
        height(1),
        rank(1) {}
    AVLTreeNode(const T& _key) :
        left(nullptr),
        right(nullptr),
        height(1),
        rank(1),
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
    const T& select(int k) const;
    void show() const;
    
private:
    void show_node(AVLTreeNode<T>* node, int gap) const;
    unsigned int height(const AVLTreeNode<T>* node) const;
    void fix_height(AVLTreeNode<T>* node);
    
    unsigned int rank(const AVLTreeNode<T>* node) const;
    void fix_rank(AVLTreeNode<T>* node);
    
    int balance_factor(const AVLTreeNode<T>* node) const;
    AVLTreeNode<T>* balance(AVLTreeNode<T>* node);
    
    AVLTreeNode<T>* rotate_left(AVLTreeNode<T>* node);
    AVLTreeNode<T>* rotate_right(AVLTreeNode<T>* node);
    AVLTreeNode<T>* add_node(AVLTreeNode<T>* node, const T& key);
    
    AVLTreeNode<T>* pop_min(AVLTreeNode<T>* node, AVLTreeNode<T>*& min_node);
    AVLTreeNode<T>* pop_max(AVLTreeNode<T>* node, AVLTreeNode<T>*& max_node);
    AVLTreeNode<T>* remove_node(AVLTreeNode<T>* node, const T& key);
    
    void remove_all(AVLTreeNode<T>* node);
    
    AVLTreeNode<T>* root;
    Compare cmp_func;
};

template<class T, class Compare>
void AVLTree<T, Compare>::show() const {
    show_node(root, 0);
}

template<class T, class Compare>
void AVLTree<T, Compare>::show_node(AVLTreeNode<T>* node, int gap) const {
    if (node) {
        show_node(node->left, gap + 1);
        for (int i = 0; i < gap; ++i) {
            cout << "    ";
        }
        cout << node->key << " " << node->height << " " << node->rank << "\n";
        show_node(node->right, gap + 1);
    }
}

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
    root = add_node(root, key);
}

template<class T, class Compare>
void AVLTree<T, Compare>::remove(const T& key) {
    root = remove_node(root, key);
}

template<class T, class Compare>
const T& AVLTree<T, Compare>::select(int k) const {
    assert(k < rank(root));
    AVLTreeNode<T>* cur_node = root;
    while (cur_node && k != rank(cur_node->left)) {
        if (k < rank(cur_node->left)) {
            cur_node = cur_node->left;
        } else {
            k = k - rank(cur_node->left) - 1;
            cur_node = cur_node->right;
        }
    }
    assert(cur_node);
    return cur_node->key;
}

template<class T, class Compare>
unsigned int AVLTree<T, Compare>::height(const AVLTreeNode<T>* node) const {
    return node ? node->height : 0;
}

template<class T, class Compare>
void AVLTree<T, Compare>::fix_height(AVLTreeNode<T>* node) {
    assert(node);
    unsigned int hl = height(node->left);
    unsigned int hr = height(node->right);
    node->height = ((hl > hr) ? hl : hr) + 1;
}

template<class T, class Compare>
unsigned int AVLTree<T, Compare>::rank(const AVLTreeNode<T>* node) const {
    return node ? node->rank : 0;
}

template<class T, class Compare>
void AVLTree<T, Compare>::fix_rank(AVLTreeNode<T>* node) {
    assert(node);
    unsigned int rl = rank(node->left);
    unsigned int rr = rank(node->right);
    node->rank = rl + rr + 1;
}

template<class T, class Compare>
int AVLTree<T, Compare>::balance_factor(const AVLTreeNode<T>* node) const {
    assert(node);
    return height(node->right) - height(node->left);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::balance(AVLTreeNode<T>* node) {
    assert(node);
    fix_height(node);
    fix_rank(node);
    if (balance_factor(node) == 2) {
        if (balance_factor(node->right) < 0) {
            node->right = rotate_right(node->right);
        }
        node =  rotate_left(node);
    } else if (balance_factor(node) == -2) {
        if (balance_factor(node->left) > 0) {
            node->left = rotate_left(node->left);
        }
        node =  rotate_right(node);
    }
    return node;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::rotate_left(AVLTreeNode<T>* node) {
    assert(node);
    AVLTreeNode<T>* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    fix_height(node);
    fix_height(tmp);
    fix_rank(node);
    fix_rank(tmp);
    return tmp;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::rotate_right(AVLTreeNode<T>* node) {
    assert(node);
    AVLTreeNode<T>* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    fix_height(node);
    fix_height(tmp);
    fix_rank(node);
    fix_rank(tmp);
    return tmp;
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::
add_node(AVLTreeNode<T>* node, const T& key) {
    if (!node) {
        return new AVLTreeNode<T>(key);
    }
    if (cmp_func(key, node->key)) {
        node->left = add_node(node->left, key);
    } else {
        node->right = add_node(node->right, key);
    }
    return balance(node);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::pop_min(AVLTreeNode<T>* node, AVLTreeNode<T>*& min_node) {
    if (!node) {
        min_node = nullptr;
        return nullptr;
    }
    if (!node->left) {
        min_node = node;
        return node->right;
    }
    node->left = pop_min(node->left, min_node);
    return balance(node);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::pop_max(AVLTreeNode<T>* node, AVLTreeNode<T>*& max_node) {
    if (!node) {
        max_node = nullptr;
        return nullptr;
    }
    if (!node->right) {
        max_node = node;
        return node->left;
    }
    node->right = pop_min(node->right, max_node);
    return balance(node);
}

template<class T, class Compare>
AVLTreeNode<T>* AVLTree<T, Compare>::
remove_node(AVLTreeNode<T>* node, const T& key) {
    if (!node) {
        return nullptr;
    }
    if (cmp_func(key, node->key)) {
        node->left = remove_node(node->left, key);
    } else if (key != node->key) {
        node->right = remove_node(node->right, key);
    } else {
        AVLTreeNode<T>* left = node->left;
        AVLTreeNode<T>* right = node->right;
        if (!left) {
            delete node;
            return right;
        }
        if (!right) {
            delete node;
            return left;
        }
        AVLTreeNode<T>* tmp_node;
        if (height(left) > height(right)) {
            node->left = pop_max(left, tmp_node);
        } else {
            node->right = pop_min(right, tmp_node);
        }
        node->key = tmp_node->key;
        delete tmp_node;
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

bool test() {
    AVLTree<unsigned int, DefaultAVLFunctor<int>> tree;
    int n = 20;
    int arr_num[20] = {1, 4, 5, 2, 6, -2, -1, -4, -6, 7, 9, 2, 1, -5, -7, -9, 10, -12, 10, 20};
    int arr_k[20] = {0, 0, 0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1};
    int answers[20] = {1, 1, 1, 2, 4, 1, 4, 5, 5, 7, 7, 5, 1, 1, 1, 2, 2, 2, 1, 2};
    
    for (int i = 0, num = 0, k = 0; i < n; ++i) {
        num = arr_num[i];
        k = arr_k[i];
        
        cout << "add " << num << "\n";
        
        if (num >= 0) {
            tree.add(num);
        } else {
            tree.remove(num * -1);
        }
        cout << "select " << k << " res - " << tree.select(k) << "\n";
        if (tree.select(k) != answers[i]) {
            return false;
        }
        tree.show();
        cout << "\n\n";
    }
    return true;
}

int main(int argc, const char * argv[]) {
    if (test()) {
        cout << "OK\n";
    } else {
        cout << "FAIL\n";
    }
    return 0;
    
    
    
    
    AVLTree<unsigned int, DefaultAVLFunctor<int>> tree;
    int n = 0;
    cin >> n;
    
    for (int i = 0, num = 0, k = 0; i < n; ++i) {
        cin >> num >> k;
        if (num >= 0) {
            tree.add(num);
        } else {
            tree.remove(num * -1);
        }
//        tree.show();
//        cout << "\n\n";
        cout << tree.select(k) << "\n";
    }
    
    return 0;
}
