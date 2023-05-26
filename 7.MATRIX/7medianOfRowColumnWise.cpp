#include <bits/stdc++.h>
using namespace std;

void print(int mat[3][3]) {
    cout << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << setw(3) << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int countSmallerThanTarget(int mat[][3], int row, int target) {
    int l = 0, h = 3; // row-size
    while (l <= h) {
        int mid = l + ((h - l) >> 1);
        if (mat[row][mid] <= target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

int medianOfMatrix(int mat[3][3]) {
    int row = 3, col = 3;
    int mn = INT_MAX, mx = INT_MIN;

    for (int i=0; i<row; i++) {
        mn = min(mn, mat[i][0]);
        mx = max(mx, mat[i][3]);
    }

    int low = mn;
    int high = mx;
    int median = (3*3+1)/2; // why + 1, bcz row and col are odd 

    while (low <= high) {
        int mid = low + ( (high - low) >> 1 ) ;
        int cnt = 0;

        for (int i=0; i<row; i++) {
            cnt += countSmallerThanTarget(mat, i, mid);
        }
        if (cnt <= median)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return low;
}


int main()
{
    int mat[][3] = {
        { 1,  2,  3}, 
        { 7,  8,  9},
        { 9, 10, 11}
    };
    cout << medianOfMatrix(mat) << endl;

    return 0;
}