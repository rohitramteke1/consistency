#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> & arr, int k) {
    int n = arr.size();
    // total groups
    int no_of_groups = n/k;
    // remaining elements
    int remaining = n%k;
    int i = 0;
    while (no_of_groups)
    {
        reverse(arr.begin() + i, arr.begin() + i + k);
        i += k;
        no_of_groups--;
    }
    reverse(arr.begin() + n - remaining, arr.end());

    for (auto &&i : arr)
    {
        cout << i << ' ';
    }
    
}

int main() {
	vector<int> arr = {0,1,2,3,4,5, 7, 8};
	int k = 1;

	solve(arr, k);

	return 0;
}