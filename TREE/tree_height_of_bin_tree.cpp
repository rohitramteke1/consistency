#include <iostream>
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
            preOrder(node->left);
            preOrder(node->right);
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

    int maxDepth(Node<T> *node) {
        if (node == NULL)
            return 0;
        else {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);
            if (lDepth > rDepth)
            {
                return lDepth + 1;
            } else {
                return rDepth + 1;
            }
        }
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

    cout << "\nHeight of tree: " << T.maxDepth(root);

    return 0;
}