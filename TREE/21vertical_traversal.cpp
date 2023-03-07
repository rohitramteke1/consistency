#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int data;
    Node() {
        left = NULL, right = NULL;
        data = 0;
    }
    Node(int data) {
        left = NULL, right = NULL;
        this->data = data;
    }
};

class Tree {
    vector<int> result;
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    
};

int main()
{
    Tree t;
    Node *root = NULL;
    root = t.insert(1);
    root->left = t.insert(2);
    root->right = t.insert(2);
    root->left->left = t.insert(3);
    root->left->right = t.insert(4);
    root->right->left = t.insert(4);
    root->right->right = t.insert(3);


    return 0;
}