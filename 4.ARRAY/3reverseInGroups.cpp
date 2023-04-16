#include <bits/stdc++.h>
using namespace std;

void revInGroups(vector<int> &arr, int n, int k) {

    int no_of_groups = n / k;
    int remaining = n % k;

    int i = 0;
    while(no_of_groups--) {
        // create a window of size, then slide that window
        auto window = begin(arr) + i;
        reverse( window, window + k);
        // now slide the window co-ordinates
        i += k;
    }

    // now reverse the remaining elements
    reverse(arr.begin() + n - remaining, arr.end());


    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int k = 3;

    revInGroups(arr, n, k);
    
    return 0;
}