#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data = 0;
    Node *next;
    Node () {
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
Node* head;
Node* first;

class LinkedList {
public:
    LinkedList() {}
    LinkedList(int data) { head = new Node(data); }

    void insertNode(int data);
    void display(Node* head);
    Node* removeDuplicates();
};

void LinkedList::insertNode(int data) {
    if (head != NULL)
    {
        first = head;
        Node* node = new Node(data);
        while (first->next != NULL)
        {
            first = first->next;
        }
        first->next = node;
        // cout << "inserted " << node->data << endl;
    }
    else {
        head = new Node(data);
        // cout << "inserted " << head->data << endl;
    }
}

void LinkedList::display(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }
}

Node* LinkedList::removeDuplicates() {
    Node *prev = head;
    Node *curr = head->next;
    while (curr->next != NULL)
    {
        if(prev->data == curr->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    LinkedList ll;
    ll.insertNode(0);
    ll.insertNode(0);
    ll.insertNode(1);
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(2);
    ll.insertNode(2);
    ll.insertNode(3);

    head = ll.removeDuplicates();

    ll.display(head);

    return 0;
}