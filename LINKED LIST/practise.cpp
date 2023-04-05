#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* getNode(int data) {
        Node* node = new Node(data);
        return node;
    }
    void createList() {
        Node* root = getNode(0);
        Node* node = root;
        for (int i = 1; i <= 20; i++)
        {
            Node* temp = getNode(i);
            node->next = temp;
            node = temp;
        }

        node = root;

        while(node) {
            cout << node->data << ' ';
            node = node->next;
        }   
    }
};

int main()
{
    LinkedList ll;
    ll.createList();

    
    return 0;
}