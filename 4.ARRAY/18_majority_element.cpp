#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {
    int n = arr.size();
    int candidate = arr[0], vote = 0;
    
    for (int i = 0; i < n; i++)
    {
        // 3 1 3 3 2
        if(candidate == arr[i])
            vote++;
        else
            vote--;
        if(vote == 0) {
            candidate = arr[i];
            vote++;
        }
    }
    return candidate;
}

int main()
{
    vector<int> arr = {3,1,3,3,2};
    cout << majorityElement(arr) << endl;
    return 0;
}