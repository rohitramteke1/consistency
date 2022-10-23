#include <iostream>
#include <vector>

using namespace std;

vector<int> easy(vector<int> arr)
{
    vector<int> res;
    bool carry = false;
    bool flag = true;
    int index = arr.size() - 1;
    int i = 0, j = 1;
    for (int k = 0; k < arr.size(); k++)
    {
        // i = size then j-> out of range
        // check the initial zeroes in vector
        if (flag && arr[i] == 0 && arr[j] == 0 && i != index + 1) 
        {
            i++, j++;
            continue;
        } 
        else if (arr[index] + 1 > 9)
        {
            carry = true, flag = false;
        } 
        else {
            carry = false, flag = false;
            arr[index] += 1;
            break;
        }
        if(carry) {
            carry = false;
            arr[index] = (arr[index] + 1) % 10;
            index--;
        }
    }

    // copy the vector and k staring from i
    for (int k = i; k < arr.size(); k++)
    {
        // do nothing, if first element contains 0 in original vector then we're 
        // copying also 0 so to avoid that we use the following logic
        if (j-1 == k && arr[k] == 0) 
            ;
        else
            res.emplace_back(arr[k]);
    }

    return res;
}

int main()
{
    // if every element contain 9 then bug is present
    // vector<int> v = {9, 9, 9, 9, 9};
    vector<int> v = {0, 9, 9, 9, 9};

    vector<int> res = easy(v);
    for (auto i : res)
    {
        cout << i << ' ';
    }
    
    return 0;
}