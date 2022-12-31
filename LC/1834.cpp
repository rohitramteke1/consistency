#include <bits/stdc++.h>
using namespace std;

void solve(vector< vector<int> > &mat) {
    for (auto &&row : mat)
    {
        for (auto &&col : row)
        {
            cout << col << ' ';
        }
        cout << endl;        
    }

}

int main()
{
    vector< vector<int> > tasks = {{1,10},{7,12},{1,5},{7,4},{7,2}};
    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].push_back(i);
    }

    sort(tasks.begin(), tasks.end());

    for (auto &&i : tasks)
    {
        for (auto &&j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    
    
        

    
    return 0;
}