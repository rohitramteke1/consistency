#include <bits/stdc++.h>
using namespace std;

int sqrtOfN(int x) {
    int low = 1;
    int high = x;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid > x) 
            high = mid - 1;
        else if (mid * mid < x) {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int x = 16;
    cout << sqrtOfN(x) << endl;
    
    return 0;
}