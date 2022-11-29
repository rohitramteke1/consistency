#include <bits/stdc++.h>
using namespace std;

// Node
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

// Some Global Nodes
Node* head;
Node* first;

// LinkedList 
class LinkedList {
public:
    LinkedList(){
        head = NULL;
    }
    // insert at begining
    bool isEmpty(Node* head) {
        if (head == NULL) return true;
        return false;
    }

    void insertNode(int data);

    // HacktoberFest Task
    void insertAtFront(int data);
    void insertInBetween(int data, int index);
    void insertAtLast(int data);
    void removeDuplicates();
    void removeDuplicates2();
    void removeDuplicatesFromUnsorted();
    void removeNodeFromLL();
    int getMiddleElement();
    Node* detectCycle();


    // display Linked-List
    void display(Node* head);
    
};

// insert Node
void LinkedList::insertNode(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        first = head;
        Node* node = new Node(data);
        while (first->next != NULL)
        {
            first = first->next;
        }
        first->next = node;
        cout << "inserted " << node->data << endl;
    }
    else {
        head = new Node(data);
        cout << "inserted " << head->data << endl;
    }
}

void LinkedList::insertAtFront(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        // create node and set the data of that node
        Node* node = new Node(data);
        // set the next of newly created node to head and
        node->next = head;
        // set the head to newly created node
        head = node;
        cout << "inserted at front: " << head->data << endl;
    } else {
        cout << "List is empty...";
    }
}

void LinkedList::insertAtLast(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        // create node and set the data of that node
        Node* node = new Node(data);
        Node* temp = head;
        // traverse the list, until we didn't get the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // we are on the last node,
        temp->next = node;
        cout << "inserted at last: " << node->data << endl;
    } else {
        cout << "List is empty...\n";
    }
}

// Insert in Between 
void LinkedList::insertInBetween(int data, int index) {
    if (!this->isEmpty(head))
    {
        int listLen = 0;
        Node* temp = head;
        while (temp!= NULL)
        {
            temp = temp->next;
            listLen++;
        }
        // check if the index is less then listLen, then and only then we can insert the 
        // node else we can't insert the node
        temp = head;
        if (index < listLen && index != 0) // if the index is 0 means we're inserting the node at head
        {
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;   
            }
            // create node
            Node* node = new Node(data);
            node->next = temp->next;
            temp->next = node;
            cout << "Inserted at index: " << index << " data: " << node->data << endl ; 
        }
        else {
            cout << "\n----- IndexOutOFRangeError...\n";
            cout << "can't insert: " << data << " at index: " << index << " list-len: " << listLen << endl ;
        }
    }
}

void LinkedList::display(Node* head) {
    Node* temp = head;
    if (head != NULL)
    {
        cout << "\nLinked-List elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        return;
    }
    cout << "Linked-List is empty...\n";
}

Node* LinkedList::detectCycle() {
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cout << "cycle\n";
            break;
        }
    }
    return head;
}

void LinkedList::removeDuplicates() {
    Node* prev = head;
    Node* curr = head->next;
    while(curr != NULL) {
        if(prev->data == curr->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }
}

void LinkedList::removeDuplicates2() {
    // you've given a sorted list
    // you've to remove all the duplicates element from the
    // including that element also
    Node* dummy = new Node(INT_MIN);
    Node* prev = dummy;

    dummy->next = head;

    while(head != NULL) {

        if(head->next != NULL && head->data == head->next->data) {
            // skip the nodes whose value are equal to head
            while(head->next != NULL && head->data == head->next->data) {
                head = head->next;
            }
            prev->next = head->next;
        }
        else {
            prev = prev->next;
        }
        head = head->next;
    }
    head = dummy->next;
}

void LinkedList::removeDuplicatesFromUnsorted() {
    // you've given unsorted list and you've to remove the duplicate
    // elements from the list
    // way-1
    // traverse the one loop for a node and other loop to 
    // check the all the values of the other nodes to the first loop node
    // O(N^2) O(1)
    // way-2: merge technique -> O(N * logN)
    // way-3: hashing O(N)

    unordered_set<int> hash_set;
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL)
    {
        if(hash_set.find(curr->data) != hash_set.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            continue;
        }
        hash_set.insert(curr->data);
        prev = curr;
        curr = curr->next;
    }
}

int LinkedList::getMiddleElement() {
    // hare and tortoise problem | floyd cycle detection
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int LinkedList::removeNodeFromLL() {
    // hare and tortoise problem | floyd cycle detection
    Node* dummy = new Node(INT_MIN);
    Node* prev = dummy;
    Node* curr = head;
    list<Node *> l;
    l.push_back(dummy);

    while(curr != NULL) {
        l.push_back(prev);
        while(l.size() > 1 && l.back()->data < curr->data) {
            l.pop();
            prev = l.back();
            prev->next = curr;
            prev = prev->next;
            curr = curr->next;
        }

        curr = curr->next;
    }

}

int main()
{
    LinkedList ll;
    ll.insertNode(6);
    ll.insertNode(6);
    ll.insertNode(49);
    ll.insertNode(49);
    ll.insertNode(30);
    ll.insertNode(30);
    ll.insertNode(40);
    ll.insertNode(40);
    ll.insertNode(5);

    ll.display(head);
    // ll.removeDuplicates();
    ll.removeDuplicatesFromUnsorted();
    ll.display(head);
    // cout << ll.getMiddleElement() << endl;
    // ll.removeDuplicates2();
    
    // ll.insertAtFront(0);
    // ll.insertAtFront(-1);
    // ll.insertAtFront(-2);
    // ll.insertAtLast(6);
    // ll.insertInBetween(100, 5);
    // ll.insertInBetween(101, 6);
    // ll.insertInBetween(102, 7);
    // ll.insertInBetween(100, 12);

    
    return 0;
}