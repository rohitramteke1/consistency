// floyd cycle detection

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

bool detectCycle(Node* head) {

    Node *slow = head;
    Node *fast = head;
    while(slow != NULL) { // floyd cycle algorithm
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

void detectCycleStartingNode(Node* head) {

    Node *slow = head;
    Node *fast = head;
    while(slow != NULL) { // floyd cycle algorithm
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            break;
        }
    }
    Node *start = head, *end = slow;
    while (start != end)
    {
        start = start->next;
        end = end->next;
    }
    cout << "node->data: " << start->data << endl;
    return;
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

    // display(head);
    cout << detectCycle(head) << endl;
    cout << detectCycleHashMap(head) << endl;
    detectCycleStartingNode(head);
    
    return 0;
}