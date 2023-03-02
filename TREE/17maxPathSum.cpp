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

    int maxPathSumUtil(Node* root) {
        if(root == NULL)
            return 0;
        
        // what iff the leftSum and rightSum becomes less than 0,
        // to ignore them, we'll return 0 or reset them as 0
        int leftSum = max(0, maxPathSumUtil(root->left) );
        int rightSum = max(0, maxPathSumUtil(root->right) );

        maximumPathSum = root->data + leftSum + rightSum;

        // now decide to move, left or right of tree
        return root->data + max( leftSum, rightSum );
    }
    int maxPathSum(Node* root) {
        maxPathSumUtil(root);
        return maximumPathSum;
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

    cout << endl << t.maxPathSum(root);

    // cout << "Postorder: ";
    // t.postOrder(root);
    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}