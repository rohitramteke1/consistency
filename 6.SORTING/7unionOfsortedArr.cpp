#include <bits/stdc++.h>
using namespace std;

// brute force solution
// this will works for any type of arr. unosorted + sorted
void unionOfTwoSortedArrays(int *a, int *b, int m, int n) {
    // O( (m + n)log(m + n) ) + O( m + n)
    vector<int> v(a, a + m);
    for (int i=0; i<n; ++i)
        v.push_back(b[i]);

    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); ++i) {
        if (i > 0 && v[i] == v[i-1]) {
            continue;
        }
        else {
            cout << v[i] << ' ';
        }
    }
}


int main()
{
    int a[] = {1,2,2,4,4,4,6};
    int b[] = {2,2,2,2,2,4,6,7};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    unionOfTwoSortedArrays(a, b, m, n);
    // intersectionUsingMerge(a, b, m, n);
    
    return 0;
}