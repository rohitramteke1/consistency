// floyd cycle detection <=> detect a cycle in linkedList

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *next;
        int data;
        Node():next(NULL), data(0) {}
        Node(int data):data(data), next(NULL){ }
};

Node* insertNode(int data){
    Node *temp = new Node(data);
    return temp;
}

void display(Node *temp) {
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

bool detectCycleHashMap(Node *head) {
    unordered_map<Node *, int> hash;
    Node* node = head;

    bool condition;
    do {
        hash[node] = node->data;
    } while (condition = hash.find(node->next) != hash.end());
    // condition ==> false ==> 0
    if(!condition) { // !condition ==> !0 => 1
        return true;
    } return false;
}


Node* detectCycle(Node* head) {

    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL) { // floyd cycle algorithm
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

void deleteCycle(Node* head) {
    Node *start = head;
    // we're assuming that, our sll contains cycle, now
    Node *meet = detectCycle(head);
    while(start->next != meet->next) {
        start = start->next;
        meet = meet->next;
    }
    meet->next = NULL;
}

int detectCycleStartingNode(Node* head) {

    Node *slow = head;
    Node *fast = head;
    Node *start = head, *meet = detectCycle(head); // detectCycle() here
    while (start != meet && meet != NULL)
    {
        start = start->next;
        meet = meet->next;
    }
    if(meet == NULL)
        return -1;
    return start->data;
}

int main()
{
    Node *seventh, *sixth, *fifth, *fourth, *third, *second, *head;

    head = insertNode(10);
    second = insertNode(20);
    third = insertNode(30);
    fourth = insertNode(40);
    fifth = insertNode(50);
    sixth = insertNode(60);
    seventh = insertNode(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = third; // cycle here

    // cout << detectCycle(head) << endl;
    // cout << detectCycleHashMap(head) << endl;
    // display(head);

    cout << "cycle node->data: " << detectCycleStartingNode(head) << endl;
    deleteCycle(head);
    display(head);

    
    return 0;
}