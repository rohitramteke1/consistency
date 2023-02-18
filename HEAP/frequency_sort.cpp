#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

vector<int> frequencySort(vector<int> &nums) {
    vector<int> result;
    priority_queue<p, vector<p>, greater<p> > pq;
    // priority_queue< p > pq;
    map<int, int> mp;
    
    for (auto &&i : nums)
        mp[i]++;
    
    for (auto &&i: mp )
    {
        int key = i.first;
        int value = i.second;

        pq.push( {value, key} );
    }
    
    while( !pq.empty() ) {
        result.emplace_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main()
{
    vector<int> nums = {4, 4, 5, 5, 6, 7, 7};

    // store the result
    vector<int> v = frequencySort(nums);

    for (auto &&i : v)
        cout << i << ' ';
    
    return 0;
}

// 6 1
// 5 2
// 4 2

/*
#include <bits/stdc++.h> 
using namespace std;

typedef pair<int, int> p;

bool myComp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
	
	int t; cin >> t;
	
    while(t--) {
    	unordered_map<int, int> mp;
    	int n; cin >> n;
    	for(int i=0; i<n; ++i) {
    	    int a; cin >> a;
    	    mp[a]++;
    	}
        
        vector< p > v( mp.begin(), mp.end() );
        
        sort( v.begin(), v.end(), myComp);
        for(auto &i: v) {
            while(i.second--) {
                cout << i.first << ' ';
            }
        }
        cout << endl;
    }
	
	return 0;
}
*/