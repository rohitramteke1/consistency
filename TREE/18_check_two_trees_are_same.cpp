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
    int maximumPathSum = 0;
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    bool areSameTree(Node* root, Node* root1){
        if(root == NULL || root1 == NULL) {
            if(root == root1)
                return true;
            return false;
        }
        if(root->data == root1->data) {
            if( areSameTree(root->left, root1->left) && areSameTree(root->right, root1->right) )
                return true;
            return false;
        }
        return false;
    }
};

int main()
{
    Tree t;
    Node *root = NULL;
    root = t.insert(1);
    root->left = t.insert(2);
    root->right = t.insert(3);
    root->left->left = t.insert(4);
    root->left->right = t.insert(5);
    root->right->left = t.insert(6);
    root->right->right = t.insert(7);

    Node *root1 = NULL;
    root1 = t.insert(1);
    root1->left = t.insert(2);
    root1->right = t.insert(3);
    root1->left->left = t.insert(4);
    root1->left->right = t.insert(5);
    root1->right->left = t.insert(6);
    root1->right->right = t.insert(7);

    cout << t.areSameTree(root, root1) << endl;

    // cout << "Postorder: ";
    // t.postOrder(root);
    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}