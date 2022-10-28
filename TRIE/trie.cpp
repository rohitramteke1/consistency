#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

class NodeTrie {
public:
    char data;
    NodeTrie* children[26];
    bool isTerminal;
    NodeTrie() {} 
    NodeTrie(char ch) {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        // memset(children, NULL, sizeof(children)); // warning
    }
};

class Trie{
public:
    NodeTrie* root;
    Trie() {
        root = NULL;
    }

    void insertWordUtil (NodeTrie* root, string word) {
        
    }
    void insertWord(string word) {
        insertWordUtil(root, word);
    }
};



int main()
{
    NodeTrie *n = new NodeTrie('\0');
    
    return 0;
}