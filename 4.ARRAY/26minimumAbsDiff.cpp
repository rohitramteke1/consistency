#include <bits/stdc++.h>
using namespace std;

int minAbsDiff(int *arr, int n) {
    vector<int> diff(n, 0);
    for (int i = 0; i < n; i++)
        diff[i] = abs( arr[i] - arr[ (i+1) % n] );
    return *min_element( diff.begin(), diff.end() );
}

int main()
{
    int n = 7;
    int arr[] = {8,-8,9,-9,10,-11,12};
    cout << minAbsDiff(arr, n) << endl;
    return 0;
}