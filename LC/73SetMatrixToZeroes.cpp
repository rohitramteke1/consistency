#include <bits/stdc++.h>
using namespace std;

// BFS
void setZeroes(vector< vector<int> > &matrix) {

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            if(matrix[i][j] == 0) {
                // column
                for (int k = 0; k < matrix[i].size(); k++)
                    matrix[i][k] *= -1;
                // row
                for (int k = 0; k < matrix[i].size(); k++)
                    matrix[k][j] *= -1;
            }
    // time complexity O(row * col * (row + col) )
    
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            if(matrix[i][j] < 0) matrix[i][j] = 0;

    for (auto &&i : matrix)
        for (auto &&j : i)
            cout << j << ' ';
        cout << endl;
}

// Better
void solve(vector< vector<int> > &matrix) {
    vector<int> row(matrix.size(), -1);
    vector<int> column(matrix[0].size(), -1);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0){
                row[i] = 0;
                column[j] = 0;
            }
        }
    }

    // for (auto &&i : row)
    // {
    //     cout << i << ' ';
    // } cout << endl;
    // for (auto &&i : column)
    // {
    //     cout << i << ' ';
    // } cout << endl;
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if(row[i] != -1 || column[j] != -1){
                matrix[i][j] = 0;
            }
        }
    }
    
    // for (auto &&i : matrix)
    // {
    //     for (auto &&j : i)
    //         cout << j << ' ';
    //     cout << endl;
    // }

}

// optimal


int main()
{
    vector< vector<int> > matrix = { {1,1,1}, {1,0,1}, {1,1,1} } ;

    // setZeroes(matrix);
    solve(matrix);
    
    
    return 0;
}