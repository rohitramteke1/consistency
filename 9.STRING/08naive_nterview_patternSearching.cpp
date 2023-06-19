// Naive Pattern Searching

bool searchPattern(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    
    for (int i=0; i<n-m+1; i++) {
        int j=0;
        for ( ; j<m; j++) {
            if (str[i + j] != pattern[j]) 
                break;
        }
        if (j == m)
            return 1;
    }
    
    return 0;
}