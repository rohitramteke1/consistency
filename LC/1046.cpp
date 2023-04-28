#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    set<int> s;
public:
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        auto it = s.begin();
        int element = *it;
        s.erase(it);
        return element;
    }
    
    void addBack(int num) {
        if ( s.find(num) == s.end() )
            s.insert(num);
    }
};


/*

class SmallestInfiniteSet {
    vector<bool> nums;
    int i; // current smallest number in set
public:
    SmallestInfiniteSet() {
        nums = vector<bool> (1001, true);
        i = 1;
    }
    
    int popSmallest() {
        int result = i;
        nums[i] = false;
        
        for(int j=i+1; j<1001; j++) {
            if ( nums[j] == true )
            {
                i = j;
                break;
            }
        }
        
        return result;
    }
    
    void addBack(int num) {
        nums[num] = true;
        if ( num < i)
            i = num;
    }
};

*/


int main()
{
    SmallestInfiniteSet s;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    s.addBack(10);
    s.addBack(11);
    s.addBack(12);
    s.addBack(13);

    return 0;
}