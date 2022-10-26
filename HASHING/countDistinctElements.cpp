#include <iostream>
#include <set> // set uses BST
using namespace std;
const int N = 1e5+10;
int arr[N];

int main()
{
    // Count the distinct number of elements in array => O(logN)
    set<int> s;
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]); // O(logN) 
    }
    cout << s.size() << endl; // O(1)

    return 0;
}