#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4,5,2,1};
    vector<int> q = {3,10,21};
    sort(arr.begin(), arr.end());

    int n = arr.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + arr[i-1];

    arr.resize(q.size(), 0);

    for (int i = 0; i < q.size(); i++)
    {
        auto index = upper_bound(prefix.begin(), prefix.end(), q[i]) - prefix.begin();
        arr[i] = index - 1;
        cout << arr[i] << ' ';
    }

    return 0;
}