#include <bits/stdc++.h>
using namespace std;

int maxOccured(int L[], int R[], int n, int range) {
    vector<int> prefix(range + 1, 0);

    for (int i = 0; i <= n; i++) {
        prefix[ L[i] ]++;
        prefix[ R[i] + 1 ]--;
    }

    for (int i = 1; i <= range + 1; i++)
        prefix[i] = prefix[i] + prefix[i-1];
    
    int ans = 0;
    int maxCount = prefix[0];

    for (int i=1; i<= range + 1; i++ ) {
        if ( maxCount < prefix[i] ) {
            maxCount = prefix[i];
            ans = i;
        }
    }
    return ans;
}

int main()
{
    int L[] = { 1 ,5 ,9 ,13 ,21 };
    int R[] = { 15,8 ,12,20 ,30 };

    int n = sizeof(L)/sizeof(L[0]);

    int range = max(
        *max_element(L, L + n),
        *max_element(R, R + n)
    );

    cout << maxOccured(L, R, n, range) << endl;

    return 0;
}