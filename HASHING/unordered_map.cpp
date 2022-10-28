// intersection and union
// hashmap and set
// hashmap is best one -=> let's see
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr1, vector<int> &arr2)
{
    set<int> _union;
    set<int> umap;

    for (int i = 0; i < arr1.size(); i++)
        _union.insert(arr1[i]);
    for (int i = 0; i < arr2.size(); i++)
        _union.insert(arr2[i]);

    for (int i = 0; i < arr1.size(); i++)
        umap.insert(arr1[i]);

    for (int i = 0; i < arr2.size(); i++)
        if (arr2[i] == *umap.find(arr2[i]))
            cout << arr2[i] << ' ';

    return 0;
}

void func(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> umap;

    for (int i = 0; i < arr1.size(); i++)
        umap[arr1[i]]++;

    for (int i = 0; i < arr2.size(); i++)
        umap[arr2[i]]++;

    for (auto &&i : umap)
        if (i.second > 1)
            cout << i.first << ' ';
}

vector<int> countTheNumber(vector<int> &arr, int n, int k)
{
    // Write your code here.
    unordered_map<int, int> hash;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (auto &&i : hash)
    {
        if (i.second >= n / k)
            v.emplace_back(i.first);
    }

    return v;
}

bool isSubSet(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // check the array is subset of another array
    unordered_map<int, int> hash;
    bool isTrue;
    for (int i = 0; i < arr1.size(); i++)
    {
        hash[arr1[i]]++;
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        isTrue = false;
        if (hash[arr2[i]] >= 1)
        {
            hash[arr2[i]]--;
            isTrue = true;
        }
        if (!isTrue)
            return false;
    }

    return isTrue;
}


int findMedian(vector<vector<int> > &arr, int n, int m) {
    for (int i = 0; i <= n/2; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    for (auto &i : arr)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return arr[(n-1)/2][(m-1)/2];
}

int main()
{

    // vector<int> arr1 = {1, 2, 3, 4, 5};
    // vector<int> arr2 = {2, 0, 3, 5, 4};
    // vector<int> arr3 = {1, 1, 2, 1, 2, 4, 3, 4};
    // vector<int> arr4 = {1, 1, 2, 1, 2, 4, 3, 4};
    // vector<int> arr5 = {1, 1, 2, 1, 2, 4, 3, 9};

    // intersection and union
        // solution(arr1, arr2);
        // cout << endl;
        // func(arr1, arr2);

    // countTheNumber()
        // vector<int> v = countTheNumber(arr3, 8, 4);
        // for (auto &&i : v)
        // {
        //     cout << i << ' ';
        // }

    // isSubSet() input 
        // int t;
        // int n, m;
        // cin >> t;
        // while (t--)
        // {
        //     cin >> n;
        //     int a;
        //     vector<int> arr;
        //     for (int i = 0; i < n; i++)
        //     {
        //         cin >> a;
        //         arr.emplace_back(a);
        //     }
        //     vector<int> brr;
        //     cin >> m;
        //     for (int i = 0; i < m; i++)
        //     {
        //         cin >> a;
        //         brr.emplace_back(a);
        //     }
                
        //     cout << endl
        //          << isSubSet(arr, brr, n, m);
        // }

    // findMedian() => codestudio
        vector< vector<int>> arr = {
            {1,3,5},
            {2,6,9},
            {3,6,9}
        };

    cout << endl << findMedian(arr, 3, 3);

    return 0;
}