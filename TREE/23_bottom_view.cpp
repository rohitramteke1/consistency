#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int data;
    Node() {
        left = NULL, right = NULL;
        data = 0;
    }
    Node(int data) {
        left = NULL, right = NULL;
        this->data = data;
    }
};

class Tree {
    vector<int> result;
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    // vertical lines concept same as vertical order traversal
    vector<int> topView(Node* root) {
        vector<int> result;
        map<int, int> mp;
        queue< pair<Node*, int> > q;
        q.push({root, root->data});

        while( !q.empty() ) {
            auto temp = q.front(); 
            q.pop();
            Node* node = temp.first;
            int level = temp.second;

            if(mp.find(level) == mp.end())
                mp[level] = node->data;
            
            if(node->left)
                q.push({node->left, level - 1});
            
            if(node->right)
                q.push({node->right, level + 1});

        }

        // now copy the values of map to result
        for (auto &key : mp)
            result.emplace_back(key.second);
        
        for (auto &&i : result)
            cout << i << ' ';
        
        return result;
    }

    vector<int> bottomView(Node* root) {
        vector<int> result;
        map<int, int> mp;
        queue< pair<Node*, int> > q;
        q.push({root, 0});

        while( !q.empty() ) {
            auto top = q.front();
            q.pop();
            Node* node = top.first;
            int level = top.second; // vertical line

            mp[level] = node->data;

            if(node->left)
                q.push({node->left, level - 1});

            if(node->right)
                q.push({node->right, level + 1});

        }

        for (auto &&i : mp)
            result.emplace_back(i.second);
        
        for (auto &&i : result)
            cout << i << ' ';
        
        return result;
    }

    
};

int main()
{
    Tree t;
    Node *root = NULL;
    root = t.insert(1);
    root->left = t.insert(2);
    root->right = t.insert(3);
    root->left->left = t.insert(4);
    root->left->right = t.insert(5);
    root->right->left = t.insert(6);
    root->right->right = t.insert(7);

    t.bottomView(root);

    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}