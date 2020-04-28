//
//  main.cpp
//  task_2_2
//
//  Created by Mac-HOME on 28.04.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

#include <iostream>
#include <functional>
#include <stack>

using std::cin;
using std::cout;
using std::function;
using std::stack;

template<class T>
class DefaultBSTFunctor {
public:
    bool operator() (const T& l, const T& r) {
        return l < r;
    }
};

template<class T>
struct BSTNode {
    BSTNode<T>* left;
    BSTNode<T>* right;
    T key;
    
    BSTNode() :
        left(nullptr),
        right(nullptr) {}
    BSTNode(T _key) :
        left(nullptr),
        right(nullptr),
        key(_key) {}
};

template<class T, class Compare = DefaultBSTFunctor<T>>
class BST {
public:
    BST();
    BST(const Compare& cmp);
    BST(const BST& root) = delete;
    BST(const BST&& root) = delete;
    ~BST();
    
    // bool has(const T& key) const;
    // void remove(const T& key);
    void add(const T& key);
    void post_order(const function<void(BSTNode<T>* node)> perform) const;
    
private:
    BSTNode<T>* root;
    Compare cmp_func;
};

template<class T, class Compare>
BST<T, Compare>::BST() :
    root(nullptr) {}

template<class T, class Compare>
BST<T, Compare>::BST(const Compare& cmp) :
    root(nullptr),
    cmp_func(cmp) {}

template<class T, class Compare>
BST<T, Compare>::~BST() {
    post_order([](BSTNode<T>* node) { delete node; });
}

template<class T, class Compare>
void BST<T, Compare>::add(const T& key) {
    BSTNode<T>* new_node = new BSTNode<T>(key);
    if (!root) {
        root = new_node;
        return;
    }
    
    bool traversed = false;
    BSTNode<T>* cur_node = root;
    while (!traversed) {
        if (cmp_func(cur_node->key, key)) {
            if (!cur_node->left) {
                cur_node->left = new_node;
                traversed = true;
            }
            cur_node = cur_node->left;
        } else {
            if (!cur_node->right) {
                cur_node->right = new_node;
                traversed = true;
            }
            cur_node = cur_node->right;
        }
    }
}

template<class T, class Compare>
void BST<T, Compare>::
post_order(const function<void(BSTNode<T>* node)> perform) const {
    if (!root) {
        return;
    }
    stack<BSTNode<T>*> nodes;
    stack<BSTNode<T>*> st;
    st.push(root);

    while (!st.empty()) {
        BSTNode<T>* cur_node = st.top();
        st.pop();
        nodes.push(cur_node);
        
        if (cur_node->right) {
            st.push(cur_node->right);
        }
        if (cur_node->left) {
            st.push(cur_node->left);
        }
    }
    
    while (!nodes.empty()) {
        BSTNode<T>* cur_node = nodes.top();
        nodes.pop();
        perform(cur_node);
    }
}

int main(int argc, const char * argv[]) {
    BST<int> tree;
    int n = 0;
    cin >> n;
    
    for (int i = 0, key = 0; i < n; ++i) {
        cin >> key;
        tree.add(key);
    }
    
    auto perform = [](BSTNode<int>* node) { cout << node->key << " "; };
    tree.post_order(perform);
    
    return 0;
}
