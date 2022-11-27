#include <bits/stdc++.h>
using namespace std;

// This is the Question is based on Matrix Chain Multiplication
// you've given a string and you've to perform the partition on that
// string and and every partition is a partition is itself a
// palindrome and return the minimum number of partition

int dp[510][510];

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

static int ik = 0;
int palindromic_partition(string s, int i, int j)
{
    ik++;
    if(j > 100) {
        unordered_map<char, int> hash;
        for (auto &&i : s)
        {
            hash[i]++;
        }
        if(hash.size() == 1) {
            return true;
        }
    }
    if (i >= j)
        return dp[i][j] = 0;
    if (isPalindrome(s, i, j))
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    int left, right;
    for (int k = i; k <= j - 1; k++)
    {
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            dp[i][k] = left = palindromic_partition(s, i, k);
        }
        if (dp[k + 1][j] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            dp[k + 1][j] = right = palindromic_partition(s, k + 1, j);
        }
        int temp = left + right + 1;
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    memset(dp, -1, sizeof(dp));
    cout << "Palindromic partition: " << palindromic_partition(s, 0, s.length() - 1);
    cout << "  " << ik << endl;
    return 0;
}