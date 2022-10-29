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
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node<T>() { this->next = NULL;}
};

template <typename T>
class SinglyLinkedList
{
    Node<T> *head = NULL;

public:
    SinglyLinkedList() : head(NULL) {}
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
    void deleteKthFromLast(int k);

    // reverse
    void reverseLinkedList();

    // display
    void display();
};

template <typename T>
void SinglyLinkedList<T>::display(){
    cout << endl;
    if (head == NULL) {
        cout << "Linked list isEmpty ..." << endl ;
        return;
    }
    Node<T> *temp = NULL;
    temp = head;
    cout << "Singly Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
void SinglyLinkedList<T>::insertNode(T data)
{
    // Create Node
    Node<T> *node = new Node(data);
    if(!isEmpty()) {
        Node<T> *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
    else head = node;
    cout << "  inserted: " << node->data << endl;
}

template <typename T>
void SinglyLinkedList<T>::insertAtFirst(T data)
{
    if(!isEmpty()) {
        Node<T> *node = new Node(data);
        node->next = head;
        head = node;
        cout << "  inserted: " << node->data << endl;
    } else {
        cout << "List is empty..." << endl;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtLast(T data)
{
    if (!isEmpty())
    {
        Node<T> *node = new Node(data);
        Node<T> *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = node;
        cout << "  inserted: " << node->data << endl;
    } else {
        cout << "List is empty...";
    }
    
}

template <typename T>
void SinglyLinkedList<T>::insertInBetween(T data, int index)
{
    if (!isEmpty())
    {
        int listLen = 0;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            ++listLen;
            temp = temp->next;
        }
        if (index > 0 && index < listLen-1)
        {
            Node<T> *prevNode = NULL, *temp = head;
            Node<T> *node = new Node(data);
            while (index-- > 0)
            {
                prevNode = temp;
                temp = temp->next;
            }
            prevNode->next = node;
            node->next = temp;
        }
        else {
            cout << "Error: IndexOutOfRangeError\n";
            cout << "can't insert " << data << " at " << index << endl;
        }
    }
    else cout << "List is empty..." << endl;
}

template <typename T>
void SinglyLinkedList<T>::deleteNode()
{
    Node<T> *temp = head, *prevNode = head;
    if (!isEmpty())
    {
        while(temp->next != NULL)
        {
            prevNode = temp;
            temp = temp->next;
        }
        // if there is only one-node(i.e. head)
        if (head == temp)
        {
            head = NULL;
            delete temp;
            return;
        }
        // more than one node
        prevNode->next = NULL;
        cout << "  deleted: " << temp->data << endl;
        delete temp;
    }
    else cout << "List is empty..." << endl;
}
template <typename T>
void SinglyLinkedList<T>::deleteAtFirst()
{
    if(!isEmpty()) {
        Node<T> *temp = head;
        head = head->next;
        cout << "  deleted: " << temp->data << endl; 
        delete temp;
    }
    else cout << "List is empty..." << endl;
}
template <typename T>
void SinglyLinkedList<T>::deleteInBetween(int index)
{
    if (!isEmpty())
    {
        int listLen = 0;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            ++listLen;
            temp = temp->next;
        }
        if (index > 0 && index < listLen-1)
        {
            Node<T> *prevNode = NULL, *temp = head;
            while (index-- > 0)
            {
                prevNode = temp;
                temp = temp->next;
            }
            prevNode->next = temp->next;
            cout << "  deleted: " << temp->data << endl;
            delete temp;
        }
        else {
            cout << "Error: IndexOutOfRangeError\n";
            cout << "can't delete at index:" << index << endl;
        }
    }
    else cout << "List is empty..." << endl;
}
template <typename T>
void SinglyLinkedList<T>::deleteAtLast()
{
    if(!isEmpty()) {
        Node<T> *temp = head, *prevNode = NULL;

        while (temp->next != NULL)
        {
            prevNode = temp;
            temp = temp->next;
        }
        if(head == temp) { // if there is only one node
            head = NULL;
            cout << "  deleted: " << temp->data << endl; 
            delete temp;
            return;
        }
        cout << "  deleted: " << temp->data << endl; 
        delete temp;
        prevNode->next = NULL;
    }
    else cout << "List is empty..." << endl;
}

template <typename T>
void SinglyLinkedList<T>::deleteKthFromLast(int k) // sliding window
{
    Node<T> *start = new Node();
    start->next = head;
    Node<T> *fast = start;
    Node<T> *slow = start;

    if(!isEmpty()) {
        for (int i = 1; i <= k; i++) // now our *fast is kth position ahead of *slow
            fast = fast->next;
        // now move the both slow and fast until fast->next != NULL
        // at this time our *slow is pointing the (k-1)th or (len-K)th element

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        // what if slow points to head => k == 1st node
        if (slow->next == head)
        {
            head = head->next;
            delete slow;
            return;
        }
        
        Node<T> *temp = slow->next;
        slow->next = slow->next->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else cout << "List is empty..." << endl;
}

template <typename T>
void SinglyLinkedList<T>::reverseLinkedList()
{
    Node<T> *next = NULL;
    Node<T> *prev = NULL;
    Node<T> *curr = head;

    if(!isEmpty()) {
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        // return prev or head => bcz both gonna points to last node
    }
    else cout << "List is empty..." << endl;
}

int main()
{
    SinglyLinkedList<int> sll;

    // insertion
    sll.insertNode(1);
    sll.insertNode(2);
    sll.insertNode(3);
    sll.insertNode(4);
    sll.insertNode(5);
    sll.insertAtFirst(0);
    sll.insertAtLast(6);
    sll.display();

    // reverse()
    sll.reverseLinkedList();
    sll.display();

    
    return 0;
}