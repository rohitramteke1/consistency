#include <iostream>
#include <array>
using ll = long long;
const int M = 1e9+7; // 10 ^ 9 + 7 --> 1000000007
using namespace std;
// ( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
// ( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
// ( a – b) % c = ( ( a % c ) – ( b % c ) ) % c
// NOT TRUE ( a / b ) % c = ( ( a % c ) / ( b % c ) ) % c

int* productOfSelfArray(int *arr, int n) {
    if(n==1) {
        cout << 1 << ' ';
        return NULL;
    }
    else {
        int flag = 0;
        int res = 1;
        int *output = new int[n];

        for (int i = 0; i < n; i++) 
        {
            if (arr[i] == 0)  
            {
                flag += 1;
            }
            else 
                res = ((res % M) * (arr[i] % M)) % M;
        }
        for (int i = 0; i < n; i++)
        {
            // if number of 0's in array is more than 1 then the product will be 0 at any cost 
            if (flag > 1)
                output[i] = 0; 

            else if(flag == 0)
                output[i] = (res / arr[i]);
                
            // it means that our array contains exactly one zero in it, and 
            // if that index doesn't contain zero, so it means that our res = 0
            else if (flag == 1 && arr[i] != 0)
                output[i] = 0;

            else // if(flag == 1 && a[i] == 0)
                output[i] = res;   
        }
    return output;
    }
}

int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "The product array is: \n";
    const int *a = productOfSelfArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    
    return 0;
}