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
    int maximumPathSum = 0;
public:
    Node *insert(int data) {
        Node *node = new Node(data);
        return node;
    }
    vector< vector<int> > BFS(Node* root) {
        vector< vector<int> > result;
        queue<Node* > q;
        q.push(root);
        while( !q.empty() ) {
            int n = q.size();
            vector<int> level;
            while(n--){
                root = q.front();
                q.pop();
                level.emplace_back(root->data);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            result.emplace_back(level);
        }

        for (auto &level : result) {
            for (auto &&i : level)
                cout << i << ' ';
            cout << endl;
        }
        
        return result;
    }

    vector< vector<int> > ZigZag(Node* root) {
        vector< vector<int> > result;
        queue<Node* > q;
        q.push(root);
        bool direction = false;
        while( !q.empty() ) {
            int n = q.size();
            vector<int> level;
            while(n--){
                root = q.front();
                q.pop();
                level.emplace_back(root->data);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            // 1 = R-L
            if(direction == true)
            {
                direction = false;
                reverse( level.begin(), level.end() );
            }
            else {
                direction = true;
            }
            result.emplace_back(level);
        }

        for (auto &level : result) {
            for (auto &&i : level)
                cout << i << ' ';
            cout << endl;
        }
        
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

    // cout << "Postorder: ";
    t.BFS(root);
    cout << endl;
    t.ZigZag(root);
    //       1
    //     2   3
    //    4 5 6 7

    return 0;
}