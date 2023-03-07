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

    bool isLeaf(Node* root){
        if(root == NULL)
            return false;
        return !root->left && !root->right;
    }

    void addChilds(Node* root) {
        if(isLeaf(root))
        {
            result.emplace_back(root->data);
            return;
        }
        if(root->left) addChilds(root->left);
        if(root->right) addChilds(root->right);
    }

    void leftBoundary(Node* root) {
        root = root->left;
        while(root) {
            if( !isLeaf(root) )
                result.emplace_back(root->data);
            if(root->left)
                root = root->left;
            else
                root = root->right;
        }
    }

    void rightBoundary(Node* root) {
        vector<int> temp;
        root = root->right;
        while(root) {
            if( !isLeaf(root) )
                temp.emplace_back(root->data);
            if(root->right)
                root = root->right;
            else
                root = root->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            result.emplace_back(temp[i]);
        
    }

    vector<int> boundaryTraversal(Node* root) {

        if(root == NULL)
            return result;
        if(!isLeaf(root))
            result.emplace_back(root->data);

        // 3 Boundaries
        leftBoundary(root);
        addChilds(root);
        rightBoundary(root);

        for (auto &&i : result)
            cout << i << ' ';

        return result;
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

    t.boundaryTraversal(root);

    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}