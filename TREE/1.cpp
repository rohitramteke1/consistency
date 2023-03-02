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
    void inOrder(Node *node) {
        if(node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << ' ';
        inOrder(node->right);
    }
    void postOrder(Node *node) {
        if(node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << ' ';
    }

    // Level Order Traversal
    void BFS(Node *root) {
        queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                cout << root->data << ' ';
            }
        }
    }

    // Iterative preOrder
    void iterativePreOrder(Node* root) {
        stack<Node *> s;
        s.push(root);
        while(!s.empty()) {
            root = s.top();
            s.pop();
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
            cout << root->data << ' ';
        }
    }

    // Same as the recursive, Just draw the recursive stack-trace
    void IterativeInOrder(Node* root) {
        stack<Node* > s;
        Node* node = root;
        vector<int> inorder;
        
        while (true)
        {
            if(node != NULL) {
                s.push(node);
                node = node->left;
            }
            else {
                if(s.empty())
                    break;
                node = s.top();
                s.pop();
                inorder.emplace_back(node->data);
                cout << node->data << ' ';
                node = node->right;
            }
        }
    }
    
    // Using two stacks
    void IterativePostOrder(Node* root) {
        stack<Node* > s;
        stack<int> postorder;
        s.push(root);
        while(!s.empty()) {
            root = s.top();
            s.pop();
            postorder.push(root->data);
            if(root->left)
                s.push(root->left);
            if(root->right)
                s.push(root->right);
        }
        while(!postorder.empty()) {
            cout << postorder.top() << ' ';
            postorder.pop();
        }
    }

    // Using One Stack
    void IterativePostOrderOneStack(Node* root) {
        stack<Node* > s;
        vector<int> postorder;
        Node* curr = root;
        while(curr != NULL || !s.empty() ) {
            if(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                Node* temp = s.top()->right;
                if(temp == NULL) {
                    temp = s.top();
                    s.pop();
                    postorder.emplace_back(temp->data);
                    cout << temp->data << ' ';
                    while(!s.empty() && temp == s.top()->right) {
                        temp = s.top();
                        s.pop();
                        cout << temp->data << ' ';
                        postorder.emplace_back(temp->data);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
    }


    void dfs(Node* root) {
        Node* curr = root;
        stack<Node* > s;
        while(curr || !s.empty() ) {
            if( curr ) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                Node* temp = s.top()->right;
                if(temp == NULL) {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << ' ';
                    while(!s.empty() && s.top()->right == temp) {
                        temp = s.top();
                        s.pop();
                        cout << temp->data << ' ';
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
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

    //      1
    //     2 3
    //    4 5
    
    // Recursive Traversal
    cout << endl;
    cout << "preOrder: ";
    t.preOrder(root);
    cout << endl;
    cout << "inOrder: ";
    t.inOrder(root);
    cout << endl;
    cout << "postOrder: ";
    t.postOrder(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    t.BFS(root);
    cout << endl;
    cout << "IterativePreOrder: ";
    t.iterativePreOrder(root);
    cout << endl;
    cout << "IterativeInOrder: ";
    t.IterativeInOrder(root);
    cout << endl;
    cout << "IterativePostOrder: ";
    t.IterativePostOrder(root);
    cout << endl;
    cout << "IterativePostOrderOneStack: ";
    t.IterativePostOrderOneStack(root);
    cout << endl;
    cout << "dfs: ";
    t.dfs(root);

    return 0;
}