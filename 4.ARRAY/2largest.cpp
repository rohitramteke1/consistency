#include <iostream>
#include <vector>

using namespace std;

int secondLargest(vector<int> &arr) {
    int secondLargest = -1;
    int largest = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if(largest < arr[i])
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(largest != arr[i]) {
            if(secondLargest == -1 or secondLargest < arr[i])
                secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{
    vector<int> arr = {5,10,12,20,8};
    cout << secondLargest(arr) << endl;
    
    return 0;
}