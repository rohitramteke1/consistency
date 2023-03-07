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

    bool isSymmetricHelper(Node* left, Node* right) {
        if(left == NULL || right == NULL )
            return left == right;
        
        if(left->data != right->data)
            return false;

        return isSymmetricHelper(left->left, right->right) && 
            isSymmetricHelper(left->right, right->left);
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

    cout << t.isSymmetricHelper(root->left, root->right);
    
    //       1
    //     2   2
    //    3 4 4 3

    return 0;
}