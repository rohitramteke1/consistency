#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Node {
public:
    Node *left;
    Node *right;
    T data;
    Node() : data(0),left(NULL), right(NULL){}
    Node(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
class Tree{
    Node<T> *head;
public:
    Node<T> *insertNode(T data) {
        Node<T> *node = new Node<T>(data);
        return node;
    }

    // root-left-right
    void preOrder(Node<T> *node) {
        Node<T> *temp;
        if (node != NULL)
        {
            cout << node->data << ' ';
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // left-right-root
    void postOrder(Node<T> *node) {
        Node<T> *temp;
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << ' ';
        }
    }

    // left-root-right
    void inOrder(Node<T> *node) {
        Node<T> *temp;
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->data << ' ';
            inOrder(node->right);
        }
    }

    // Non recursive traversing of tree
    void nonRecursivePreOrder(Node<T> *node) {
        stack<Node<T> *> s;
        s.push(node);
        while (!s.empty())
        {
            Node<T> *currentNode = s.top();
            cout << currentNode->data << ' ';
            s.pop();
            if (currentNode->right != NULL)
                s.push(currentNode->right);

            if (currentNode->left != NULL)
                s.push(currentNode->left);
        }
    }

    void nonRecursivePostOrder(Node<T> *node) {
        stack<Node<T> *> s;
        s.push(node);
        vector<int> v;

        while (!s.empty())
        {
            Node<T> *currentNode = s.top();
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
    
    void nonRecursiveInOrder(Node<T> *node) {
        stack<Node<T> *> s; 
        Node<T> *currentNode = node;
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

    int height(Node<T> *root) {
        if(root == NULL) return 0;
        int lDepth = height(root->left);
        int rDepth = height(root->right);
        if (lDepth > rDepth)
            return lDepth + 1;
        else
            return rDepth + 1;
    }
};

int main()
{
    Tree<int> T;
    Node<int> *root;
    //           10
    //         /    \
    //        4     14
    //       / \   /   \
    //      3   5 13   20

    // PreOrder: 10 4 3 5 14 13 20
    // InOrder: 3 4 5 10 13 14 20
    // PostOrder: 4 3 5 14 13 20 10

    root = T.insertNode(10);
    root->left = T.insertNode(4);
    root->right = T.insertNode(14);
    root->left->left = T.insertNode(3);
    root->left->right = T.insertNode(5);
    root->right->left = T.insertNode(13);
    root->right->right = T.insertNode(20);
    root->right->right->left = T.insertNode(19);
    root->right->right->right = T.insertNode(25);

    cout << "\nPreOrder: ";
    T.preOrder(root);
    cout << "\nInOrder: ";
    T.inOrder(root);
    cout << "\nPostOrder: ";
    T.postOrder(root);

    cout << "\nNon Rec PreOrder: "; 
    T.nonRecursivePreOrder(root);
    cout << "\nNon Rec InOrder: ";
    T.nonRecursiveInOrder(root);
    cout << "\nNon Rec PostOrder: ";
    T.nonRecursivePostOrder(root);

    cout << "Height of tree: " << T.height(root) << endl ;

    return 0;
}