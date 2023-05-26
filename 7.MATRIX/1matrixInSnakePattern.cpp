#include <bits/stdc++.h>
using namespace std;

// Solution 1
void printMatrixInSnakePatternS1(int mat[4][4])
{
    bool reverse = false;

    for (int row = 0; row < 4; row++)
    {
        if (reverse == false) {
            reverse = true;
            for (int col = 0; col < 4; col++)
                cout << setw(3) << mat[row][col] << ' ';
        }
        else {
            reverse = false;
            for (int col = 3; col >= 0; col--)
                cout << setw(3) << mat[row][col] << ' ';
        }
        cout << endl;
    }
}

// Solution 2
void printMatrixInSnakePattern(int mat[4][4])
{
    for (int row = 0; row < 4; row++)
    {
        if (row % 2 == 0) {
            for (int col = 0; col < 4; col++)
                cout << setw(3) << mat[row][col] << ' ';
        }
        else {
            for (int col = 3; col >= 0; col--)
                cout << setw(3) << mat[row][col] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int mat[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    printMatrixInSnakePattern(mat);

    return 0;
}