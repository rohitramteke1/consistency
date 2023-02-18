#include <bits/stdc++.h>
using namespace std;

/*
    MinHeap
        • Largest • Greatest • Top
    MaxHeap
        • Smallest • Lowest • Closest
*/

typedef pair<int, int> p;

vector<int> frequentElements(vector<int> &nums, int k) {
    vector<int> result;

    priority_queue< p, vector<p>, greater<p> > pq;
    map<int, int> mp;

    for (auto &i : nums)
        mp[i]++;

    for (auto &i : mp)
    {
        int key = i.first;
        int value = i.second;
        
        pq.push( {value, key} );

        if(pq.size() > k) {
            pq.pop();
        }
    }
    
    while ( !pq.empty() )
    {
        result.emplace_back( pq.top().second );
        pq.pop();
    }

    return result;
}

vector<int> topK(vector<int> &nums, int k) {
    priority_queue< p > pq;
    unordered_map<int, int> mp;

    // O(N + N + K * logN + N) ~= O(NlogN)
    // O(N + N) => O(2N) ~= O(N)
    for (auto &&i : nums)
        mp[i]++;
    
    nums.clear();

    for (auto &&i : mp)
        pq.push({i.second, i.first});
    
    while( k-- ) {
        nums.emplace_back( pq.top().second );
        pq.pop();
    }

    return nums;
}

int main()
{
    vector<int> nums = {1,1,2,2,2,3,3};
    int k = 2;

    vector<int> v = topK(nums, k);
    for (auto &&i : v)
        cout << i << ' ';
    
    
    return 0;
}