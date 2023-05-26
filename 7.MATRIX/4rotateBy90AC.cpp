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

void rotateBy90AntiClockWise(int mat[4][4])
{
    int row = 4, col = 4;
    print(mat);
 
    int m[row][col];
    
    for (int i=0; i<row; i++) {
        // main line
        reverse(mat[i], mat[i] + row);
        for (int j=0; j<col; j++) {
            m[j][i] = mat[i][j];
        }
    }
    
    // copy to the original mat
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            mat[i][j] = m[i][j];
        }
    }

    print(mat);
}

// Solution 2
void rotateBy90AntiClockWise2(int mat[4][4])
{
    // last col becomes first row
    // sec-last col becomes sec-row.... and so on

    int row,col;
    row = col = 4;
    print(mat);
 
    int m[row][col];
    
    for (int i=0; i < row; i++) {
        for (int j=0; j < row; j++) {
            m[row-1-j][i] = mat[i][j];
        }
    }
    
    // copy to the original mat
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            mat[i][j] = m[i][j];
        }
    }

    print(mat);
}

// Solution 3
void rotateBy90AntiClockWise3(int mat[4][4])
{
    // last col becomes first row
    // sec-last col becomes sec-row.... and so on

    int row,col;
    row = col = 4;
    print(mat);
    
    for (int i=0; i < row; i++) {
        for (int j=i+1; j < row; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    print(mat);
    
    for (int i=0; i < row; i++) {
        int low = 0, high = row - 1;
        while (low < high) {
            swap(mat[low][i], mat[high][i]);
            low++, high--;
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
    rotateBy90AntiClockWise3(mat);

    return 0;
}