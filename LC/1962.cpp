#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Optimal
int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;
    int sum = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        maxHeap.push(piles[i]);
        sum += piles[i];
    }
    while(k--) {
        int stones = maxHeap.top();
        sum = sum - stones/2;
        stones = stones - stones/2;
        if(stones == 1) return sum;
        maxHeap.pop();
        maxHeap.push(stones);
    }
    return sum;
}

int minStoneSumBetter(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < piles.size(); i++)
    {
        maxHeap.push(piles[i]);
    }

    while(k--) {
        int a = maxHeap.top();
        if(a & 1) {
            a = a/2 + 1;
        } else {
            a = a/2;
        }
        maxHeap.pop();
        maxHeap.push(a);
    }
    int ans = 0;
    while(!maxHeap.empty())
    {
        ans += maxHeap.top();
        maxHeap.pop();
    }
    return ans;
}

int main()
{
    vector<int> piles = {4,3,6,7};
    int k = 3;
    // better
    cout << minStoneSum(piles, k) << endl;
    return 0;
}