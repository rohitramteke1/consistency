#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {0,0,0,0,0,0,0,0,0};
    int cnt = 1;
    int ans = 0;
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if(arr[i-1] == arr[i] && arr[i] == 1) {
            cnt++;
            ans = max(cnt, ans);
        } else {
            cnt = 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}