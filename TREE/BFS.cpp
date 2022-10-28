#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int data;
    Node() : data(0),left(NULL), right(NULL){}
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{
    Node* head;
public:
    // create and insert node
    Node* insertNode(int data) {
        Node* node = new Node(data);
        return node;
    }

    // root-left-right
    void preOrder(Node* node) {
        Node* temp;
        if (node != NULL)
        {
            cout << node->data << ' ';
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // left-right-root
    void postOrder(Node* node) {
        Node* temp;
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << ' ';
        }
    }

    // left-root-right
    void inOrder(Node* node) {
        Node* temp;
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->data << ' ';
            inOrder(node->right);
        }
    }

    // Non recursive traversing of tree
    void nonRecursivePreOrder(Node* node) {
        stack<Node* > s;
        s.push(node);
        while (!s.empty())
        {
            Node* currentNode = s.top();
            cout << currentNode->data << ' ';
            s.pop();
            if (currentNode->right != NULL)
                s.push(currentNode->right);

            if (currentNode->left != NULL)
                s.push(currentNode->left);
        }
    }

    void nonRecursivePostOrder(Node* node) {
        stack<Node* > s;
        s.push(node);
        vector<int> v;

        while (!s.empty())
        {
            Node* currentNode = s.top();
            s.pop();
            v.emplace_back(currentNode->data);

            if (currentNode->left != NULL)
                s.push(currentNode->left);

            if (currentNode->right != NULL)
                s.push(currentNode->right);
        }
        // actually all the elements are stored in descending manner so, we'll print
        // it in the reverse order or we can use the stack here
        for (auto i = v.rbegin(); i != v.rend(); i++)
            cout << *i << ' ';
    }
    
    void nonRecursiveInOrder(Node* node) {
        stack<Node* > s; 
        Node* currentNode = node;
            while (currentNode != NULL || !s.empty())
            {
                while (currentNode != NULL)
                {
                    s.push(currentNode);
                    currentNode = currentNode->left;
                }
                currentNode = s.top();
                s.pop();
                cout << currentNode->data << ' ';
                currentNode = currentNode->right;
            }
        return;
    }
    
    int height(Node* root) {
        if(root == NULL) return 0;

        int lDepth = height(root->left);
        int rDepth = height(root->right);

        if(lDepth > rDepth) {
            return lDepth+1;
        } else {
            return rDepth+1;
        }
    }

    // level order traversal [Recursive]
    void levelOrderTraversal(Node* node) {
        
    }

    // non recursive
    void BFSTraversal(Node* root) {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            root = q.front();
            if (root == NULL) // print the data level-by-level
            {
                q.pop(); // removes the null and
                if (q.empty())
                    return;
                cout << endl;
                q.push(NULL); // at the end of q
                continue;
            }
            cout << root->data << ' ';
            q.pop();
            if(root->left != NULL) {
                q.push(root->left);
            }
            if(root->right != NULL) {
                q.push(root->right);
            }            
        }
    }
};

int main()
{
    Tree T;
    Node* root;

    root = T.insertNode(10);
    root->left = T.insertNode(4);
    root->right = T.insertNode(14);
    root->left->left = T.insertNode(3);
    root->left->right = T.insertNode(5);
    root->right->left = T.insertNode(13);
    root->right->right = T.insertNode(20);
    root->right->right->left = T.insertNode(19);
    root->right->right->right = T.insertNode(25);

    T.BFSTraversal(root);
    cout << endl << "Height: " << T.height(root);

    return 0;
}