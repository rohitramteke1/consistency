#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute Force
int trap(vector<int>& height) {
    int n = height.size();
    int rain = 0;

    for (int i = 1; i < n-1; i++)
    {
        int left = height[i], right = height[i];
        for (int j=i-1; j >= 0; j--) 
            left = max(left, height[j]);
        for (int j=i+1; j<=n; j++)
            right = max(right, height[j]);
        rain += min(left, right) - height[i];
    }

    return rain;
}

int optimal(vector<int>& height) {
    int n = height.size();
    int rain = 0;
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = height[0];
    right[n-1] = height[n-1];

    for (int i=1; i<n; i++) {
        left[i] = max(left[i-1], height[i]);
        right[n-1-i] = max(height[n-1-i], right[n-i]);
    }
    for (int i = 0; i < n; i++)
        rain += min(left[i], right[i]) - height[i];
    

    return rain;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(height);
    cout << ans << endl;
    return 0;
}
