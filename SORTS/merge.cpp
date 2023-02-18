#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> v;

    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;

    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            v.emplace_back(a[i]);
            i++;
        }
        else {
            v.emplace_back(b[j]);
            j++;
        }
    }
    while(i < n1) {
        v.emplace_back(a[i]);
        i++;
    }
    while(j < n2) {
        v.emplace_back(b[j]);
        j++;
    }

    

    return v;
}

int main()
{
    vector<int> arr1 = {1,3,6};
    vector<int> arr2 = {2,4,5};
    vector<int> v = merge(arr1, arr2);
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}