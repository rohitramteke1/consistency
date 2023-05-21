#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid <= hi) {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid++], arr[lo++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
}

// Algorithm 2
class Solution
{
    public:
    void sort012(int *arr, int n) {
        int lo = 0;
        int mid = 0;
        int hi = n-1;
        while(mid <= hi) {
            switch (arr[mid])
            {
            case 0:
                swap(arr[mid], arr[lo]);
                mid++; lo++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[hi]);
                hi--;
                break;
            }
        }
    }
};