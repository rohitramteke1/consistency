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

class Queue {
    Node *_front, *_rear;
    int _size;
public:
    Queue(): _size(0), _front(NULL), _rear(NULL) {}

    bool empty(){
        if (_rear != NULL)
            return false;
        return true;
    }
    void push(int data){
        Node* node = new Node(data);
        _size++;
        if(!empty()){
            _rear->next = node;
            _rear = node;
        }
        if(_rear == NULL) { // for single element
            _rear = _front = node;
        }
    }
    void pop(){
        if (!empty())
        {
            Node* temp;
            temp = _front;
            if (_rear == _front)
            {
                _rear = _front = NULL;
                delete temp;
                return;
            }
            _front = _front->next;
            delete temp;
        }
    }
    int front(){
        return _front->data;
    }
    int back(){
        return _rear->data;
    }
    int size(){
        return _size;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    cout << q.size() << endl;
    cout << q.front() << ' ' << q.back() << endl; 
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}