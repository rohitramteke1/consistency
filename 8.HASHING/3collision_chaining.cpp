#include <iostream>

class Node {
public:
    Node* next;
    int data;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Hashing Chaining
class HashTable {
    Node* hash[7];
    int mod = 7;
public:

    HashTable() {
        for (int i=0; i<mod; i++) 
            hash[i] = nullptr;
    }

    int generateHashKey(int key) {
        int hashKey = key % mod;
        return hashKey;
    }

    void insert(const int key) {
        int hash_key = generateHashKey(key);
        
        std::cout << hash_key << std::endl;
        
        if (hash[hash_key] == nullptr) {
            Node* node = new Node(key);
            hash[hash_key] = node;
            std::cout << "Inserted: " << hash[hash_key]->data << std::endl;
        }
        else {
            std::cout << "for key: "<< key << " collision takes place \n";
            Node* curr = hash[hash_key];
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new Node(key);
            std::cout << "Inserted: " << key << std::endl;
        }
    }

    bool search(int key) {
        int hash_key = generateHashKey(key);
        if (hash[hash_key] != nullptr) {
            Node* curr = hash[hash_key];
            while (curr) {
                if (curr->data == key)
                    return 1;
                curr = curr->next;
            }
        }
        return 0;
    }

    void del(const int key) {
        if (search(key)) {
            int hash_key = generateHashKey(key);

            Node* curr = hash[hash_key];
            Node* prev = nullptr;
            while (curr) {
                // find the key
                if (key == curr->data) {
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            // delete the last key
            if (curr == nullptr) {
                prev->next = nullptr;
                delete curr;
            }
            // first key
            else if (prev == nullptr) {
                hash[hash_key]->next = curr->next;
            }
            // somewhere in the middle
            else {
                prev->next = curr->next;
                delete curr;
            }
            std::cout << key << " deleted successfully\n";
        }
        else {
            std::cout << key << "KeyNotFoundError\n";
        }
    }
};

int main()
{
    int arr[] = {21,58,17,15,49,56,22,23,25};
    int n = sizeof(arr)/sizeof(arr[0]);

    HashTable hsh;
    
    for (int i=0; i<n; i++)
        hsh.insert(arr[i]);

    hsh.del(21);
    hsh.del(49);
    hsh.del(23);
    hsh.del(24);

    return 0;
}