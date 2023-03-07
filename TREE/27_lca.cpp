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
    
    Node* lca_helper(Node* root, Node* p, Node* q) {
        if(root == NULL)
            return NULL;
        if(root == p)
            return p;
        if(root == q)
            return q;

        Node* left = lca_helper(root->left, p, q);
        Node* right = lca_helper(root->right, p, q);

        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
    }

    Node* lowestCommanAncestors(Node* root, Node* p, Node* q) {
        return lca_helper(root, p, q);
    }

    // brute force
    // O(2N) + O(2N)
    void lca(Node* root, int p, int q) {
        vector<Node* > path1;
        vector<Node* > path2;
        getPath(root, path1, p);
        getPath(root, path2, q);

        for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
        {
            if(path1[i] == path2[j])
                root = path1[i];
            else
                break;
        }
        
        cout << root->data << endl;
    }

    // O(N) + O(H)
    bool getPath(Node* root, vector<Node* > &path, int x) {
        if(root == NULL)
            return false;

        path.push_back(root);
        
        if(root->data == x)
            return true;

        if( getPath(root->left, path, x) || getPath(root->right, path, x) )
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
    root->left->left->left = t.insert(8);
    root->left->right = t.insert(5);
    root->right->left = t.insert(6);
    root->right->left->right = t.insert(9);
    root->right->right = t.insert(7);

    t.lca(root, 8,9);

    //       1
    //     2   3
    //    4 5 6 7
    //   8     9

    
    return 0;
}