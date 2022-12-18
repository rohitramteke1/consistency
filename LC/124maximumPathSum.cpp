#include <bits/stdc++.h>
using namespace std;

int maxPathSum(TreeNode* root) {
    DFS(root, maxSum);
    return maxSum;
}

int DFS(TreeNode* root, int& maxSum){
    if(root == NULL) return 0;
    int left = max(0, DFS(root->left, maxSum));
    int right = max(0, DFS(root->right, maxSum));
    maxSum = max(maxSum, left + right + root->val);
    return max(left, right) + root->val;
}

int main()
{

    
    return 0;
}