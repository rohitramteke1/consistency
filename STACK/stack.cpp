#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int data) : data(data), next(NULL) {}
};

class SinglyLinkedList
{
    Node *head;
public:
    SinglyLinkedList() : head(NULL) {}
    void insertNode(int data)
    {
        Node *node = new Node(data);
        if (head != NULL)
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = node;
            return;
        }
        head = node;
    }

    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }
};

class Stack {
    Node* _top_;
    int _size_;
public:
    Stack(): _size_(0), _top_(NULL) {}
    bool empty(){
        if (_top_ != NULL)
            return false;
        return true;
    }
    void push(int data){
        Node* node = new Node(data);
        ++_size_;
        if(!empty()) {
            node->next = _top_;
            _top_ = node;
            return;
        }
        _top_ = node;
    }

    void pop(){
        if (!empty() && _top_ != NULL)
        {
            Node* temp = _top_;
            _top_ = _top_->next;
            delete temp;
        }
    }

    int top(){
        if(!empty()) return _top_->data;
        return -1;
    }

    int size(){
        return _size_;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << "size: " << s.size() << endl ;
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}