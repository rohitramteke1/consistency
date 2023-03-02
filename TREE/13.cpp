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
    public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    void preOrder(Node *node) {
        if(node == NULL)
            return;
        cout << node->data << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }
    void singleLoopTraversal(Node* root) {
        vector<int> preorder;
        vector<int> inorder;
        vector<int> postorder;
        stack< pair<Node*, int> > s;
        s.push({root, 1}); 

        while( !s.empty() ) {
            auto it = s.top();
            root = it.first;
            s.pop();

            if(it.second == 1) {
                preorder.emplace_back(root->data);
                it.second++;
                s.push(it);

                // if its left exists
                if(root->left)
                    s.push({root->left, 1});
            }
            else if(it.second == 2) {
                inorder.emplace_back(root->data);
                it.second++;
                s.push(it);

                // if its right exists
                if(root->right)
                    s.push({root->right, 1});
            }
            else {
                postorder.emplace_back(root->data);
            }
        }

        cout << "\nPreorder: ";
        for (auto &&i : preorder)
            cout << i << ' ';
            
        cout << "\nInorder: ";
        for (auto &&i : inorder)
            cout << i << ' ';

        cout << "\nPostorder: ";
        for (auto &&i : postorder)
            cout << i << ' ';

    }
    int maxDepth(Node* root) {
        if(root == NULL) 
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
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

    t.singleLoopTraversal(root);
    cout << endl << t.depth(root) << endl;

    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}