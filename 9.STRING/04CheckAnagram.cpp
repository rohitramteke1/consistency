class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if (a.length() != b.length())
            return false;
            
        vector<int> hash_a(26, 0);
        
        // like moore voting technique
        for (int i=0; i<a.length(); i++) {
            hash_a[a[i] - 'a']++; 
            hash_a[b[i] - 'a']--;
        }
        
        for (int i=0; i<26; i++) 
            if (hash_a[i] != 0) 
                return 0;
    
        return 1;
    }

};