#include <bits/stdc++.h>
using namespace std;

class HashTable {
    vector<int> hash;
public:
    HashTable() {
        hash.resize(1001, -1);
    }
    bool search(int key) {
        if (hash[key] != -1)
            return 1;
        return 0;
    }
    void insert(int key) {
        hash[key] = 1;
    }
    void del(int key) {
        if (!search(key))
            return;
        else 
            hash[key] = 0;
    }
};

int main()
{
    HashTable hashObj;
    cout << hashObj.search(10) << endl;
    hashObj.insert(10);
    hashObj.insert(11);
    hashObj.del(12);
    cout << hashObj.search(10) << endl;

    return 0;
}