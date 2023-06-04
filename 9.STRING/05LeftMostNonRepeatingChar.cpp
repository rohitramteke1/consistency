// Better: Two Traversals
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       char ch = '$';
       
       int n = S.length();
       vector<int> hash(26, 0);
       
       for (int i=0; i<n; i++) {
           hash[S[i] - 'a']++;
       }
       for (int i=0; i<n; i++) {
           if (hash[S[i] - 'a'] == 1) {
               return S[i];
           }
       }
       
       return ch;
    }

};


// Optimal O(N + c) c is constant
class Solution
{
    const int CHAR = 256;
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       int n = S.length();
       vector<int> hash(CHAR, -1);
       
       for (int i=0; i<n; i++) {
           if (hash[S[i]] == -1)
               hash[S[i]] = i;
           else
               hash[S[i]] = -2;
       }
       
       int res = INT_MAX;
       for (int i=0; i<CHAR; i++) {
           if (hash[i] >= 0) {
               res = min(res, hash[i]);
           }
       }
       
       return (res != INT_MAX) ? S[res] : '$';
    }

};