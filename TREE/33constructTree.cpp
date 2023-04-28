#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *left, *right;
    int data;
    Node () {
        left = NULL, right = NULL;
        data = 0;
    }
    Node (int data) {
        left = NULL, right = NULL;
        this->data = data;
    }
};

class Tree {
public:
    Node* buildTreeHelper(vector<int> &postorder, vector<int> &inorder, 
        int inStart, int inEnd, int postStart, int postEnd ) {
        
        if (inStart > inEnd)
            return nullptr;

        Node* root = new Node(postorder[postEnd]);

        int i = inStart;
        for (; i <= inEnd; i++)
        {
            if (inorder[i] == root->data) {
                break;
            }
        }
        
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root->left  = buildTreeHelper(postorder, inorder, inStart, i-1, postStart, postStart + leftSize - 1);
        root->right = buildTreeHelper(postorder, inorder, i+1, inEnd, postEnd - rightSize, postEnd - 1);

        return root;
    }

    Node* buildTree(vector<int> &postorder, vector<int> &inorder) {
        int n = inorder.size();
        int inStart = 0;
        int inEnd = n-1;
        int postStart = 0;
        int postEnd = n-1;

        return buildTreeHelper(postorder, inorder, inStart, inEnd, postStart, postEnd);
    }

    void inorder(Node* root) {
        if(root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << ' ';
        inorder(root->right);
    }

};

int main()
{
    Tree T;
    vector<int> postOrder = {8, 4, 5, 2, 6, 7, 3, 1};
    vector<int> inOrder = {4, 8, 2, 5, 1, 6, 3, 7};

    Node* root = T.buildTree(postOrder, inOrder);
    T.inorder(root);

    return 0;
}