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

    // using level order traversal
    // TC: O(N) + O(N/2)
    vector<int> leftView(Node* root) {
        queue<Node* > q;
        vector<int> result;
        q.push(root);
        while( !q.empty() ) {
            int n = q.size(); 
            while(n--) {
                root = q.front();
                q.pop();
                if(root->right)
                    q.push(root->right);
                if(root->left)
                    q.push(root->left);
            }
            cout << root->data << ' ';
        }

        return result;
    }

    // using level order traversal
    // TC: O(N) + O(N/2)
    vector<int> rightView(Node* root) {
        queue<Node* > q;
        vector<int> result;
        q.push(root);
        while( !q.empty() ) {
            int n = q.size(); 
            while(n--) {
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            cout << root->data << ' ';
        }

        return result;
    }

    // Recursive + O(N) + O(H)
    void rightViewTree(Node* root, int level) {
        if(root == NULL)
            return;
        if(result.size() == level)
            result.emplace_back(root->data);

        rightViewTree(root->right, level + 1);
        rightViewTree(root->left, level + 1);
    }
    // Recursive + O(N) + O(H)
    void leftViewTree(Node* root, int level) {
        if(root == NULL)
            return;
        if(result.size() == level)
            result.emplace_back(root->data);

        leftViewTree(root->left, level + 1);
        leftViewTree(root->right, level + 1);
    }

    void reset() {
        result.clear();
    }
    void print() {
        for (auto &&i : result)
            cout << i << ' ';
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

    cout << endl << "Iterative leftView: ";
    t.leftView(root);
    cout << endl << "Iterative rightView: ";
    t.rightView(root);
    
    cout << endl << "Recursive leftView: ";
    t.leftViewTree(root, 0);
    t.print();
    t.reset();

    cout << endl << "Recursive rightView: ";
    t.rightViewTree(root, 0);
    t.print();
    t.reset();
    
    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}