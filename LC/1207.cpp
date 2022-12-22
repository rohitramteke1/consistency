#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,2,1,1,2};
    unordered_map<int, int> umap;
    unordered_set<int> uset;

    for (auto &&i : arr) umap[i]++;

    for (auto &&i : umap) {
        if(uset.find(i.second) != uset.end()) {
            cout << false << endl;
            break;
        }
        uset.insert(i.second);
    }
    
    return 0;
}