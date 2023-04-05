#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = getNode();
    }
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        for(int i=0; i<26; ++i)
            newNode->children[i] = NULL;
        newNode->isEndOfWord = false;
        return newNode;
    }
    void insert(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            int index = c - 'a';
            if(crawler->children[index] == NULL)
                crawler->children[index] = getNode();
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }
    bool serach(string word) {
        TrieNode* crawler = root;
        for(char c : word) {
            int index = c - 'a';
            if(crawler->children[index] == NULL)
                return false;
            crawler = crawler->children[index];
        }
        // return crawler != NULL && crawler->isEndOfWord == true;
        return crawler && crawler->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        int i = 0;
        for(; i < prefix.length(); ++i) {
            int index = prefix[i] - 'a';
            if(crawler->children[index] == NULL)
                return false;
            crawler = crawler->children[index];
        }
        return i == prefix.length();
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("abp");

    cout << t.serach("apple") << endl;
    cout << t.startsWith("apple") << endl;
    cout << t.startsWith("abz") << endl;
    
    return 0;
}