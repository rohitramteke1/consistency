#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    unordered_map<int, int> hash;

    for(int i=0; i<arr.size(); ++i) 
        hash[arr[i]]++;

    for (auto &&i : hash)
        cout << i.second << endl;
    
    
    return 0;
}