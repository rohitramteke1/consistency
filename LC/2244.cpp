#include <bits/stdc++.h>
using namespace std;

// O(NlogN) + O(1)
int minimumRoundsSort(vector<int>& tasks) {
    // edge case
    if(tasks.size() == 1) return -1;
    int round = 0, cnt =  1;
    tasks.push_back(INT_MAX);
    sort(tasks.begin(), tasks.end() );
    
    for(int i=1; i<tasks.size(); ++i) {
        if(tasks[i-1] == tasks[i]) {
            cnt++;
        }
        else 
        {
            if(cnt == 1) return -1;
            if(cnt % 3 == 0) round += cnt/3;
            else round += cnt/3 + 1;
            cnt = 1;
        }
    }
    return round == 0 ? -1 : round;
}

// O(2 * N)
int minimumRounds(vector<int>& tasks) {
    int round = 0;
    unordered_map<int, int> umap;
    for (auto &&i : tasks)
        umap[i]++;
    
    for (auto &&i : umap)
    {
        if(i.second <= 1) return -1;
        else if(i.second == 2) {
            round += 1;
        }
        else{
            round += ceil(double(i.second/3.0) );
        }
    }
    return round;
}

int main()
{
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    // cout << minimumRoundsSort(tasks) << endl;
    cout << minimumRounds(tasks) << endl;
    
    return 0;
}