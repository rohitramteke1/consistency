#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> v) {
    int size = v.size();
    for (int i = 0, j=size-1; i < size/2; i++, j--) // O(N) ~= O(N/2)
        if(j>i) 
        {
            swap(v[i], v[j]);
            cout << v[i] << ' ' << v[j] << endl ;
        }

    for(auto i:v) {
        cout << i << ' ' ;
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    rev(v);
    
    return 0;
}