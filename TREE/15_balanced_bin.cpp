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
    int diameter = 0;
    public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    void preOrder(Node* root) {
        stack<Node* > s;
        vector<int> preorder;
        s.push(root);
        while( !s.empty() ) 
        {
            root = s.top();
            s.pop();
            preorder.emplace_back(root->data);
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
        }
        for (auto &&i : preorder)
        {
            cout << i << ' ';
        }
    }
    void inOrder(Node* root) {
        stack<Node* > s;
        vector<int> inorder;
        while(true) {
            if(root != NULL) {
                s.push(root);
                root = root->left;
            }
            else {
                if(s.empty())
                    break;
                else {
                    root = s.top();
                    s.pop();
                    inorder.emplace_back(root->data);
                    root = root->right;
                }
            }
        }

        for (auto &&i : inorder)
        {
            cout << i << ' ';
        }
    }

    // using one stacks
    void postOrder(Node* root) {
        stack<Node*> s;
        Node* curr = root;
        vector<int> postorder;

        while(curr || !s.empty() ) {
            if(curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                Node* temp = s.top()->right;
                if(temp == NULL) {
                    temp = s.top();
                    s.pop();
                    postorder.emplace_back(temp->data);
                    while(!s.empty() && s.top()->right == temp) {
                        temp = s.top();
                        s.pop();
                        postorder.emplace_back(temp->data);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
        for (auto &&i : postorder)
        {
            cout << i << ' ';
        }
    }

    // O(N) + O(H)
    int maxDepth(Node* root) {
        if(root == NULL) 
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }

    // O(N) + O(H)
    int isBalancedBinaryTree(Node* root) {
        if(root == NULL)
            return 0;
        int lh = isBalancedBinaryTree(root->left);
        int rh = isBalancedBinaryTree(root->right);

        // Conditions for ! balanced binary tree
        if(lh == -1 || rh == -1)
            return -1;
        if(abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }

    // O(N^2) + O(H)
    bool isBalanced(Node* root) {
        if(root == NULL)
            return true;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if(abs(lh-rh) > 1)
            return false;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(left == false || right == false)
            return false;
        return true;
    }

    // diameter of tree is also called as Maximum width of binary Tree
    int diameterOfTreeUtil(Node* root) {
        if(root == NULL)
            return 0;

        int lh = diameterOfTreeUtil(root->left);
        int rh = diameterOfTreeUtil(root->right);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfTree(Node* root) {
        diameter = 0;
        diameterOfTreeUtil(root);
        return diameter;
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
    root->right->right->right = t.insert(8);
    root->right->right->right->right = t.insert(9);

    // cout << endl << t.maxDepth(root);
    cout << endl << t.isBalancedBinaryTree(root);
    cout << endl << t.isBalanced(root);
    cout << endl << t.diameterOfTree(root);

    // cout << "Postorder: ";
    // t.postOrder(root);
    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}