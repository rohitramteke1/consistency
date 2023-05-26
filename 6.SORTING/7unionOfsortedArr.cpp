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

// optimal Solution 
// technique similar to merge sort
vector<int> findUnion(int a[], int b[], int m, int n)
{
    vector<int> unionResult;
    
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        
        if (i > 0 && a[i] == a[i-1]) {i++; continue; }
        if (j > 0 && b[j] == b[j-1]) {j++; continue; }
        
        if (a[i] < b[j]) {
            unionResult.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]) {
            unionResult.push_back(b[j]);
            j++;
        }
        else {
            unionResult.push_back(a[i]);
            i++, j++;
        }
    }
    
    while ( i < m) {
        if ( i == 0 || (a[i] != a[i-1]) )
            unionResult.push_back(a[i]);
        i++;
    }
            
    while ( j < n) {
        if ( j == 0 || (b[j] != b[j-1]) )
            unionResult.push_back(b[j]); 
        j++;            
    } 
    
    for (auto &&i : unionResult)
        cout << i << ' ';
    
    return unionResult;
}

int main()
{
    int a[] = {1, 4, 18, 19, 19, 28, 29, 32, 35, 35, 39, 39, 44, 49, 49, 50, 50};
    int b[] = {8, 34};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    findUnion(a, b, m, n);
    // intersectionUsingMerge(a, b, m, n);
    
    return 0;
}