#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> a) {
    int numOfSwaps;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size()-i-1; j++)
        {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                numOfSwaps++;
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << ' ';
        }
        
        cout << endl ;
    }
    printf("Array is sorted in %d swaps.\n", numOfSwaps);
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size()-1] << endl;    
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
    
    
}

int main()
{
    vector<int> a;
    int e, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        a.emplace_back(e);
    }
    bubbleSort(a);
    
    return 0;
}