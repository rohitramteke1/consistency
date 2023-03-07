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
    vector<int> path;
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    vector<int> rootToNodePath(Node* root, int x) {
        if(root == NULL)
            return {};
        if(root->data == x)
            return {x};

        helper(root, x);

        return path;
    }
    bool helper(Node* root, int x) {
        if(root == NULL)
            return false;
        path.push_back(root->data);
        if(root->data == x)
            return true;
        bool lh = helper(root->left, x);
        if(lh == true)
            return true;
        bool rh = helper(root->right, x);
        if(rh == true)
            return true;

        // at this moment lh and rh should be false, so 
        // we can avoid this if condition and we can directly write as
        // path.pop_back();
        if(lh == false && rh == false)
            path.pop_back();
        return false;
    }

    // O(N) + O(H)
    bool getPath(Node* root, int x) {
        if(root == NULL)
            return false;

        path.push_back(root->data);
        
        if(root->data == x)
            return true;

        if( getPath(root->left, x) || getPath(root->right, x) )
            return true;

        path.pop_back();
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
    root->left->right->left = t.insert(6);
    root->left->right->right = t.insert(7);
    // root->right->left = t.insert(6);
    // root->right->right = t.insert(7);
    // root->right->right->right = t.insert(8);
    // root->right->right->right->right = t.insert(9);

    //       1
    //     2   3
    //    4 5 6 7
    //           8
    //            9

    vector<int> result = t.rootToNodePath(root, 7);
    for (auto &&i : result)
    {
        cout << i << ' ';
    }
    
    return 0;
}