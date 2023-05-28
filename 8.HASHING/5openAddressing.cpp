#include <iostream>
#include <vector>
using namespace std;

// -1 empty slot
// -2 deleted

class MyHash {
    vector<int> hsh;
    int cap, size;
public:
    MyHash(int c) {
        cap = c;
        size = 0;
        hsh.resize(cap, -1);
    }

    int hash(int key) {
        return key % cap;
    }

    bool search(int key) {
        int h = hash(key);
        int i = h;
        // we'll stop at 3 conditions
        // 1. hsh[i] == -1
        // 2. empty slot
        // 3. coming back to same position
        while (hsh[i] != -1) {
            if (hsh[i] == key)
                return true;
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }

    bool insert(int key) {
        // hash table is full
        if (size == cap)
            return 0;
        int i = hash(key);
        while (hsh[i] != -1 && hsh[i] != -2 && hsh[i] != key)
            i = (i + 1) % cap;
        if (hsh[i] == key)
            return 0;
        else {
            size++;
            hsh[i] = key;
            return 1;
        }
    }

    bool erase(int key) {
        if (size == cap)
            return 0;
        int i = hash(key);
        while (hsh[i] != -1 && hsh[i] != -2 && hsh[i] != key)
            i = (i + 1) % cap;
        if (hsh[i] == key) {
            hsh[i] = -2;
            return 0;
        }
        else {
            size++;
            hsh[i] = key;
            return 1;
        }
    }
};

int main() {
    int arr[] = {21,7,14,35,49,56,22};
    int n = sizeof(arr)/sizeof(arr[0]);

    MyHash ht(7);
    
    // insert
    for (int i=0; i<n; i++)
        ht.insert(arr[i]);

    for (int i=0; i<n; i++)
        std::cout << ht.search(arr[i]) << '\n';


    return 0;
}