#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector< vector<int> > dp;
    int ROW = 3;
    int COL = 5;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> v;
        for (int j = 0; j < COL; j++)
        {
            v.emplace_back(j+1);
        }
        // vector<int> v(COL);
        // for (int j = 0; j < COL; j++)
        // {
        //     v[j] = (j+1);
        // }
        dp.emplace_back(v);
    }
    
    for (auto &&i : dp)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    

    return 0;
}