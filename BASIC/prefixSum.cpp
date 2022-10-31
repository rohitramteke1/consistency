// Trapping rainwater problem
// Pre Processing of an array or 
// pre computation technique

#include <iostream>
using namespace std;

const int N = 1e5+10;
int prefixSum[N];
int suffixSum[N];

// prefixSum
void prefix(int a[], int n) {
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + a[i];
        cout << prefixSum[i] << ' ';
    }
}
// suffixSum
void suffix(int a[], int n) {
    for (int i = n; i >= 1; i--)
    {
        suffixSum[i] = suffixSum[i+1] + a[i];
        cout << suffixSum[i] << ' ';
    }
}

int trappingRainWater(int a[], int n) {
    int rain = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > prefixSum[i-1])
            prefixSum[i] = a[i];
        else
            prefixSum[i] = prefixSum[i-1];
    }

    for (int i = n; i >= 1; i--)
    {
        if (a[i] > suffixSum[i+1])
            suffixSum[i] = a[i];
        else
            suffixSum[i] = suffixSum[i+1];
    }

    for (int i = 0; i <= n; i++)
    {
        rain = rain + min(prefixSum[i], suffixSum[i]) - a[i];
    }
    
    return rain;
}



int main()
{
    
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << trappingRainWater(a, n);
    
    
    return 0;
}