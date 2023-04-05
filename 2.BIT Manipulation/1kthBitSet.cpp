#include <bits/stdc++.h>
using namespace std;

// & -> 1 when both bits are 1
// | -> 0 when both bits are 0
// ^ -> 1 when both bits are diff viceversa
// ~ -> negation... flip all the bits 0 <=> 1 and 1 <=> 0
// >> -> left shift by one bit
// << -> right shift by one bit

bool isKthBitSet(int n, int k) {
    // apporach - 1
    // it'll shift the right most k bits
    while(k--) {
        n = n >> 1;
    }
    return n | 0;
}

bool isBitSet(int n, int k) {
    return (n >> k) | 1;
}

bool leftShift(int n, int k) {
    // k = 3 
    // (k - 1) << 1 => 2 << 1
    // 2 << 1 := 2 * 2 ^ 1 => 2 ^ 2
    // 2^2 => 1 0 0
    // n = 5 => 1 0 1


    return ((k-1) << 1) & n;
}

int main()
{
    signed int x = 1;
    // cout << ~x << endl;
    // x = 5;
    // cout << ~x << endl;

    // we're assuming that the bits index are starting 
    // from 0 then, 0 1 2 . . . .
    cout << isKthBitSet(5, 2) << endl;
    cout << isBitSet(5, 2) << endl;

    return 0;
}