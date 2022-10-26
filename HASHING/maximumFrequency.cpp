#include <bits/stdc++.h>
using namespace std;
// maximum frequency, if two or more than two nums in array have the same freq. then
// return the number which has lowest index in array
int maximumFrequency(vector<int> arr)
{
    int ans = 0;
    int maxFreq = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < arr.size(); i++)
    {
        // 10, 20, 20, 30, 40, 10, 20, 30, 10
        hash[arr[i]]++;
        // hash[arr[i]] = hash[arr[i]] + 1;
        maxFreq = max(maxFreq, hash[arr[i]]);
    }

    // for (auto iter = hash.begin(); iter != hash.end(); iter++)
    //     cout << iter->first << ' ' << iter->second << endl;

    int maxi = INT_MIN; // counts

    for(int i=0; i<arr.size(); i++)
    {
        if(maxFreq == hash[arr[i]]) {
            ans = arr[i];
            break;
        }
    }

    return ans;
}
int main()
{
    vector<int> arr = {10, 20, 20, 30, 40, 10, 20, 30, 10};
    cout << "ans: " << maximumFrequency(arr) << endl;

    return 0;
}