#include <bits/stdc++.h>
using namespace std;

// O(N) + O(N)
int maxiIndexDiff(vector<int> &arr) {
    int n = arr.size();
    int maxIndexDiff = 0;

    unordered_map< int, int> first;
    unordered_map< int, int> last;

    for (int i = 0; i < n; i++)
    {
        if( first.find( arr[i] ) == first.end() )
            first[arr[i]] = i;
        last[ arr[i] ] = i;
    }
    
    for (auto &i : arr)
        maxIndexDiff = max(maxIndexDiff, last[i] - first[i] );

    return maxIndexDiff;
}

// O(N) + O(N)
int better(vector<int> &arr) {
    int n = arr.size();
    int maxIndexDiff = 0;

    unordered_map< int, pair<int, int> > mp;

    for (int i=0; i<n; i++)
    {
        // first  + second
        // first  -> first + second
        // arr[i] -> first + second
        if( mp.find(arr[i]) == mp.end() )
            mp[ arr[i] ].second.first = i;
        mp[ arr[i] ].second.second = i;
    }

    for(auto &i : mp)
        maxIndexDiff = max(maxIndexDiff, i.second.second - i.second.first);

    return maxIndexDiff;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4, 2, 1, 5, 1, 7};
    cout << maxiIndexDiff(arr) << endl;
    return 0;
}