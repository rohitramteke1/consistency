#include <bits/stdc++.h>
using namespace std;

// Solution 1
void printBoundaryTraversal(int mat[4][4])
{
    int row = 4, col = 4;
    for (int i=0; i<col; i++)
        cout << mat[0][i] << ' ';

    for (int i=1; i<row; i++)
        cout << mat[i][col-1] << ' ';

    for (int i=col-2; i >= 0; i--)
        cout << mat[row-1][i] << ' ';

    for (int i=row-2; i >= 1; i--)
        cout << mat[i][0] << ' ';

}

// optimised
vector<int> boundaryTraversal(vector<vector<int> > &mat, int row, int col) 
{
    // code here
    vector<int> boundary;
    
    if (row == 1)
        for (int i=0; i<col; i++)
            boundary.push_back(mat[0][i]);
    
    else if (col == 1)
        for (int i=0; i<row; i++)
            boundary.push_back(mat[i][0]); 
    else {
            
        for (int i=0; i<col; i++)
            boundary.push_back( mat[0][i] );
    
        for (int i=1; i<row; i++)
            boundary.push_back( mat[i][col-1] );
    
        for (int i=col-2; i >= 0; i--)
            boundary.push_back( mat[row-1][i] );
    
        for (int i=row-2; i >= 1; i--)
            boundary.push_back( mat[i][0] );
            
    }
        
    return boundary;
}


int main()
{
    int mat[][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };
    printBoundaryTraversal(mat);

    return 0;
}