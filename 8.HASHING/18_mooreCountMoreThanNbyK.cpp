#include <bits/stdc++.h>
using namespace std;

// O(nk)
// TODO - NOT WORKING PROPERLY
int moore(int arr[], int n, int k) {
    unordered_map<int, int> mp;

    for (int i=0; i<n; i++) {
        if ( mp.find(arr[i]) != mp.end() )
            mp[arr[i]]++;
        else if (mp.size() < n / k)
            mp[arr[i]]++; 
        else {
            for (auto iter = mp.begin(); iter != mp.end(); ) {
                iter->second--;
                auto i = iter++;
                if (i->second == 0)
                    mp.erase(i);
            }
        }
    }

    int totalCount = 0;

    for (int i=0; i<n; i++) {
        if (mp.find(arr[i]) != mp.end()) {
            totalCount++;
            mp.erase(arr[i]);
        }
    }

    return totalCount;
}

int main()
{
    int arr[] = {10,10,5,10,20}; // 5 10 20
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << moore(arr, n, 2) << endl;

    return 0;
}