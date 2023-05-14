#include <bits/stdc++.h>
using namespace std;

// Zoho Microsoft Snapdeal Goldman Sachs Adobe Linkedin Amdocs Brocade Juniper Networks Quikr Synopsys

// optimal solution-1
void merge(long long a[], long long b[], int n, int m) 
{ 
    int last = n-1;
    int first = 0;
    while (last >= 0 and first < m) {
        if (a[last] > b[first]) 
        {
            swap(a[last], b[first]);
            last--, first++;
        }
        else
            break;
        
    }
    sort(a , a + n);
    sort(b , b + m);
} 



// Gap Method - Shell Sort
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) 
{
    // code here 
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0) {
        
        int left = 0;
        int right = left + gap;
        
        while (right < len) {
            // arr1 and arr2
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            
            // arr2 and arr2
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            
            // arr1 and arr1
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}



int main()
{
    int a = {1,3,5,7};
    int b = {2,6,8,9};
    
    return 0;
}