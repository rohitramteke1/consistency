#include <bits/stdc++.h>
using namespace std;

void print(int mat[4][4]) {
    cout << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << setw(3) << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

void spiralTraversal(int mat[4][4])
{
    int row = 4;
    int top, left, bottom, right;
    top = left = 0, bottom = right = row - 1;
    
    while (top <= bottom && left <= right) {
        // top row
        for (int i=left; i<=right; i++)
            cout << mat[top][i] << ' ';
            top++;
        
        // right column
        for (int i=top; i<= bottom; i++)
            cout << mat[i][right] << ' ';
            right--;
        
        // bottom row
        if (top <= bottom) {
            for (int i=right; i>=left; i--)
                cout << mat[bottom][i] << ' ';
                bottom--;
        }
        
        // left column
        if (left <= right) {
            for (int i=bottom; i>=top; i--)
                cout << mat[i][left] << ' ';
                left++;
        }
    }

    print(mat);
}


int main()
{
    int mat[][4] = {
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8}, 
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    spiralTraversal(mat);

    return 0;
}