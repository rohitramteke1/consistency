#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;
    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insertWord(string word) {
        insertWordUtil(root, word);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    // Util member-functions
    void insertWordUtil (TrieNode* root, string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) // O( N * children_size=26)
        {
            if(node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new TrieNode();

            node = node->children[word[i] - 'a'];
        }
        node->isLeaf = true;
    }

    bool searchUtil(TrieNode* root, string word) {

        if(root == NULL) return false;
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->children[word[i] - 'a'];
            if(node == NULL) return false;
        }
        return node->isLeaf;
    }

    bool startWith(string word) {
        return startWithUtil(root, word);
    }

    bool startWithUtil(TrieNode *root, string word) {
        if(root == NULL) return false;
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->children[word[i] - 'a'];
            if(node == NULL) return false;
        }
        return true;
    }

};

int main()
{
    Trie t;
    t.insertWord("app");
    t.insertWord("apple");
    t.insertWord("applet");
    t.insertWord("apply");
    t.insertWord("applying");
    
    cout << t.search("app") << endl;
    cout << t.startWith("apple") << endl;
    
    return 0;
}