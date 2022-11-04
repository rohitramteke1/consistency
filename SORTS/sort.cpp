#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &arr);
void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size()-1; i++)
    {
        for (int j = 0; j < arr.size()-i-1; j++)
        {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        print(arr);
    }
}
void insertionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        int min_idx = i;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        if(min_idx != i) 
            swap(arr[min_idx], arr[i]);
        print(arr);
    }
}
void selectionSort(vector<int> &arr) {
    int key;
    for (int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        j++;
        arr[j] = key;
        print(arr);
    }
}
void print(vector<int> &arr) {
    cout << endl;
    for (auto &&i : arr)
        cout << i << ' ';
}
int main()
{
    vector<int> arr = {6,5,4,3,2,1};
    // 6 5 4 3 2 1

    // 6 5 4 3 2 1
    // 5 6 4 3 2 1
    // 4 5 6 3 2 1 
    // 3 4 5 6 2 1 
    // 2 3 4 5 6 1
    // 1 2 3 4 5 6

    print(arr);
    // bubbleSort(arr);
    cout << endl;
    // insertionSort(arr);
    cout << endl;
    selectionSort(arr);

    
    return 0;
}