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

int searchInRowAndColumnWiseSortedMatrix(int mat[4][4], int key) {
    int row = 4, col = 4;

    int i, j;
    i = 0, j = col - 1;
    
    while (i < row && j >= 0) {
        if (mat[i][j] == key)
            return  key;
        else if (key > mat[i][j]) {
            i++;
        }
        else if (key < mat[i][j]) {
            j--;
        }
    }

    return -1;
}


int main()
{
    int mat[][4] = {
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8}, 
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << searchInRowAndColumnWiseSortedMatrix(mat, 15) << endl;

    return 0;
}