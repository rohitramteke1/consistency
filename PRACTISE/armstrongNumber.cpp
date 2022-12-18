#include <bits/stdc++.h>
using namespace std;

int digits(int n) {
    int cnt = 0;
    while(n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

string armstrongNumber(int n){
    int N = n;
    int power = digits(n);
    long long int ans = 0;
    while(n) {
        ans += pow(n%10, power);
        n /= 10;
    }
    // cout << power << endl;
    // cout << ans << endl;
    return (ans == N) ? "Yes" : "No";
}
int main()
{
    int n = 153;
    cout << armstrongNumber(n) << endl;
    
    return 0;
}