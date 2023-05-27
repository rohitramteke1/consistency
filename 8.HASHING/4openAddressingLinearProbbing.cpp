#include <iostream>
#include <cstring>

// Hashing Open Addressing - Linear Probbing
class HashTable {
    int hash[7];
    const int mod = 7;
public:

    HashTable() {
        memset(hash, -1, sizeof(hash));
    }

    int generateHashKey(const int key) {
        int hashKey = key % mod;

        // check the empty slot
        if (hash[hashKey] == -1)
            return hashKey;

        else {
            int prevHash = hashKey;
            do {
                // do modular arithemetic
                hashKey = ( hashKey + 1 ) % mod;

                // hashTable is filled
                if (prevHash == hashKey or hash[hashKey] == key)
                    break;
            } while (hash[hashKey] != -1);

            if (hash[hashKey] == -1 or hash[hashKey] == key)
                return hashKey;
            return -1;
        }
    }

    void insert(const int key) {
        int hash_key = generateHashKey(key);
        if (hash_key == -1) {
            std::cout << key << " Hash Table is completely filled" << std::endl;
            return;   
        }
        hash[hash_key] = key;
        std::cout << key << " inserted at " << hash_key << std::endl;
    }

    bool search(const int key) {
        int hash_key = generateHashKey(key);

        if (hash_key == -1)
            return 0;
    
        int prevHash = hash_key;

        if (hash[hash_key] == key)
            return 1;
            
        do {
            hash_key = (hash_key + 1) % mod;
            if (prevHash == hash_key)
                return 0;
        } while (hash[hash_key] != key) ;

        // this time hash_key may be different, line 55
        if (hash[hash_key] == key)
            return 1;

        return 0;
    }

    void del(const int key) {

        if (search(key)) {
            int hash_key = generateHashKey(key);

            while (hash[hash_key] != key) {
                hash_key = (hash_key + 1) % mod;
            }

            if (hash[hash_key] == -1) {
                std::cout << key << " KeyNotFoundError\n";
                return;
            } 

            hash[hash_key] = -1;
            std::cout << key << " deleted successfully\n";
        }
        else {
            std::cout << key << " KeyNotFoundError\n";
        }

    }
};

int main()
{
    int arr[] = {21,7,14,35,49,56,22};
    int n = sizeof(arr)/sizeof(arr[0]);

    HashTable hsh;
    
    // insert
    for (int i=0; i<n; i++)
        hsh.insert(arr[i]);

    // Search 
    std::cout << "Result: " << hsh.search(21) << std::endl;
    std::cout << "Result: " << hsh.search(49) << std::endl;
    std::cout << "Result: " << hsh.search(7) << std::endl;
    std::cout << "Result: " << hsh.search(14) << std::endl;
    std::cout << "Result: " << hsh.search(419) << std::endl;

    // delete all keys
    for (int i=0; i<n; i++)
        hsh.del(arr[i]);

    // one by one
    hsh.del(21);
    hsh.del(21);

    return 0;
}