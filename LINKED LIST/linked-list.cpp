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
    LinkedList(int data) {
        head = new Node(data);
    }
    void insertNode(int data);
    void display(Node* head);
    
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




int main()
{
    LinkedList ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(2);
    ll.insertNode(1);
    ll.display(head);

    Node* temp = head;
    vector<int> v;
    while (temp != NULL)
    {
        v.emplace_back(temp->data);
        temp = temp->next;
    }
    
    int len = v.size();
    bool flag = true;
    for (int i=0; i<len/2; i++)
    {
        if (v[i] != v[len-1-i])
        {
            flag = false;
            break;
        }
    }
    flag ? cout << "true" << endl : cout << "false" << endl ;

    return 0;
}