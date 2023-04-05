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
    Node(int data, Node* left, Node* right) {
        left = NULL, right = NULL;
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree {
    vector< vector<int> > result;
    map<int, map<int, multiset<int> > > mp;
    
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    // Striver's Appraoch Leetcode Solution
    vector< vector<int> > vot(Node* root) {

        queue< pair<Node*, pair<int, int> > > q;
        q.push({root, {0, 0}});

        while( !q.empty() ) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int col = p.second.first;
            int row = p.second.second;

            mp[col][row].insert(node->data);

            if(node->left)
                q.push({ node->left, {col - 1, row + 1} });
            if(node->right)
                q.push({ node->right, {col + 1, row + 1} });
        }

        for (auto &vl_and_map : mp)
        {
            vector<int> temp;
            for (auto &&m_set : vl_and_map.second)
                temp.insert(temp.end(), m_set.second.begin(), m_set.second.end() );

            result.emplace_back(temp);
        }

        for (auto &&i : result)
            for (auto &&j : i)
                cout << j << ' ';
            cout << endl;
        
        return result;
    }

    // GFG Solution
    vector<int> DFS(Node* root) {

        queue< pair<Node*, int > > q;
        q.push({root, 0});
        vector<int> ans;

        map<int, vector<int> > hsh;
        
        while( !q.empty() ) {
            auto p = q.front(); q.pop();
            Node* node = p.first;
            int col = p.second;

            hsh[col].push_back(node->data);

            if(node->left)
                q.push({ node->left, col - 1});
            if(node->right)
                q.push({ node->right, col + 1});
        }

        for (auto &i : hsh)
            ans.insert(ans.end(), i.second.begin(), i.second.end());

        for (auto &&i : ans)
            cout << i << ' ';
        
        return ans;
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

    t.DFS(root);

    return 0;
}