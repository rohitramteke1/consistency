#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,3};
    int ct = 0;
    int k = 3;
    for (int i = 0; i < arr.size(); i++)
    {
        // 1 2 3
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if(sum == k) {
                ct++;
                break;
            }
        }
    }
    cout << ct << endl;
    
    return 0;
}