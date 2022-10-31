#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int data) : data(data),left(NULL), right(NULL) {}
};

class Tree {
    Node *root;
public:
    Tree(): root(NULL) {}

    Node* createNode(int data) {
        Node* node = new Node(data);
        return node;
    }

    void levelOrderTraversal(Node* node) {
        queue< Node* > q;
        q.push(node);
        q.push(NULL);
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            if(node == NULL) {
                if(q.empty()) 
                    return;
                q.push(NULL);
                cout << endl;
                continue;
            }
            cout << node->data << ' ';
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    void inOrder(Node* root) {
        if(root == NULL) return;

        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if(root == NULL) return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
    }

    void preOrder(Node* root) {
        if(root == NULL) return;

        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }

    int treeMax(Node* root) {
        if(root == NULL) 
            return INT_MIN;
        
        int lmax = treeMax(root->left);
        int rmax = treeMax(root->right);

        int res = root->data;

        if(lmax > res) 
            res = lmax;
        if(rmax > res) 
            res = rmax;
        return res;
    }

    int treeMin(Node* root) {
        if(root == NULL) 
            return INT_MAX;
        
        int lmin = treeMin(root->left);
        int rmin = treeMin(root->right);

        int res = root->data;

        if(lmin < res) 
            res = lmin;
        if(rmin < res) 
            res = rmin;
        return res;
    }

    bool isBST(Node* root) {
        if(root == NULL) return true;
        
        return false;
    }
};

int main()
{   
    Tree t;
    //      20
    //     10 30
    //   5 15 25 35
    Node *root = t.createNode(20);
    root->left = t.createNode(10);
    root->right = t.createNode(30);
    root->left->left = t.createNode(5);
    root->left->right = t.createNode(15);
    root->right->left = t.createNode(25);
    root->right->right = t.createNode(35);

    t.levelOrderTraversal(root);

    cout << "TreeMin: " << t.treeMax(root) << endl;
    cout << "TreeMax: " << t.treeMin(root) << endl;
    return 0;
}