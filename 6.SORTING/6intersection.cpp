#include <bits/stdc++.h>
using namespace std;

// brute force solution
// this will works for any type of arr. unosorted + sorted
void intersectionOfTwoSortedArray(int *a, int *b, int m, int n) {

    for (int i=0; i<m; ++i) {

        // skip
        if (i > 0 && a[i] == a[i-1])
            continue;

        for (int j=0; j<n; ++j) {

            if (a[i] == b[j]) {
                cout << a[i] << ' ';
                break;
            }
        }
    }
}

// if the arrays are sorted then we'll use merge sort technique
void intersectionUsingMerge(int a[], int b[], int m, int n) {
    int i=0, j=0;
    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i-1]) {
            ++i;
            continue;
        }
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else {
            cout << a[i] << ' ';
            i++, j++;
        }
    }
}


int main()
{
    int a[] = {1,2,2,4,4,4,6};
    int b[] = {2,2,2,2,2,4,6,7};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    // intersectionOfTwoSortedArray(a, b, m, n);
    intersectionUsingMerge(a, b, m, n);
    
    return 0;
}