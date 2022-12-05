#include <iostream>
#include <vector>
#include <stack>
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
    Node* reverseLL(Node* last);
    bool isPalindrome();
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

Node* LinkedList::reverseLL(Node* last) {
    Node *prev = head;
    Node *curr = head;
    Node *next = curr->next;
    while(curr->next != last && curr->next != NULL) {
        curr->next = next->next;
        next->next = prev;
        prev = next;
        next = curr->next;
    }
    return prev;
    // stack<Node* > s;
    // Node* node = head;
    // while(node != NULL) {
    //     s.push(node);
    //     node = node->next;
    // }
    // Node* dummy = new Node(0);
    // node = dummy;

    // while(!s.empty()) {
    //     cout << s.top()->data << ' ';
    //     node->next = s.top();
    //     s.pop();
    //     node = node->next;
    // }
    // node->next = NULL;
    // return dummy->next;
}

bool LinkedList::isPalindrome() {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *start = reverseLL(slow);
    Node *mid = (fast == NULL) ? slow: slow->next;

    while(start != slow) {
        if(start->data != mid->data) 
            return false;
        start = start->next;
        mid = mid->next;
    }

    return true;
}

int main()
{
    LinkedList ll;
    ll.insertNode(0);
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(2);
    ll.insertNode(1);
    ll.insertNode(0);

    // head = ll.removeDuplicates();

    // ll.display(head);
    // Node* newHead = ll.reverseLL(NULL);
    // head = newHead;
    cout << endl;
    // ll.display(newHead);
    cout << ll.isPalindrome();

    return 0;
}