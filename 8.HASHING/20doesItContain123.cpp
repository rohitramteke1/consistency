// https://practice.geeksforgeeks.org/problems/numbers-containing-1-2-and-32555/1

// it is given in the question
// unordered_map<int, int> mp;

bool doesItContains123(int n) {
    while (n) {
        int rem = n % 10;
        if (rem != 1 and rem != 2 and rem != 3) 
            return false;
        n /= 10;
    }
    return 1;
}

void findAll() {
    //code here
    
    int n = 1e6 + 2;
    
    for (int i=1; i<n; i++) {
        if ( doesItContains123(i) ) {
            mp[i] = 1;
        }
    }
}