#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = getNode();
    }
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        // for(int i=0; i<26; ++i)
        //     newNode->children[i] = NULL;
        memset(newNode->children, 0, sizeof(newNode->children));
        newNode->isEndOfWord = false;
        return newNode;
    }
    void insert(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            short index = c - 'a';
            if(crawler->children[index] == NULL)
                crawler->children[index] = getNode();
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            short index = c - 'a';
            if(crawler->children[index] == NULL)
                return false;
            crawler = crawler->children[index];
        }
        return crawler && crawler->isEndOfWord;
    }
    bool startsWith(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            short index = c - 'a';
            if(crawler->children[index] == NULL)
                return false;
            crawler = crawler->children[index];
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("rohit");
    t.insert("rohan");
    t.insert("rahul");
    cout << t.search("rahul") << endl;
    cout << t.startsWith("on") << endl;
    
    return 0;
}