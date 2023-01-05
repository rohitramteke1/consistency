#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &strs) {
    int cnt = 0;
    for (int i = 0; i < strs.size()-1; i++) // for rows
    {
        for (int j = 0; j < strs[i].length(); j++) // for columns
        {
            cout << strs[i][j] << ' ';
            if(strs[j][i] > strs[j+1][i]) {
                cnt++;
                break;
            }
        }
        cout << endl;
    }
    return cnt;
}

int main()
{
    vector<string> strs = {"zyx","wvu","tsr"};
    // "c b a"
    // "d a f"
    // "g h i"
    cout << minDeletionSize(strs) << endl;
    
    return 0;
}