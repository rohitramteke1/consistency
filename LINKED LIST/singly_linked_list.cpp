// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T = int> // default int
class Node
{
public:
    Node<T> *next;
    T data;
    Node<T>()
    { // Node()
        next = NULL;
        data = 0;
    }
    Node<T>(T data)
    { // or Node(T data)
        next = NULL;
        this->data = data;
    }
};

template <typename T>
class SinglyLinkedList
{
    Node<T> *head = NULL;

public:
    SinglyLinkedList()
    { // SinglyLinkedList()
        head = NULL;
    }
    bool isEmpty() {
        if(head == NULL) return true;
        return false;
    }
    // insertion
    void insertNode(T data);
    void insertAtFirst(T data);
    void insertInBetween(T data, int index);
    void insertAtLast(T data);

    // deletion
    void deleteNode();
    void deleteAtFirst();
    void deleteInBetween(int index);
    void deleteAtLast();
};

template <typename T>
void SinglyLinkedList<T>::insertNode(T data)
{
    // Create Node
    Node<T> *node = new Node(data);
    if(!isEmpty()) {

        return;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtFirst(T data)
{
}

template <typename T>
void SinglyLinkedList<T>::insertAtLast(T data)
{
}

template <typename T>
void SinglyLinkedList<T>::insertInBetween(T data, int index)
{
}

template <typename T>
void SinglyLinkedList<T>::deleteNode()
{
}
template <typename T>
void SinglyLinkedList<T>::deleteAtFirst()
{
}
template <typename T>
void SinglyLinkedList<T>::deleteInBetween(int index)
{
}
template <typename T>
void SinglyLinkedList<T>::deleteAtLast()
{
}

int main()
{
    SinglyLinkedList<int> sll;
    sll.insertNode();

    return 0;
}