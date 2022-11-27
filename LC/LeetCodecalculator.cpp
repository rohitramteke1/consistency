// CPP program to check if k-th bit
// of a given number is set or not
#include <bits/stdc++.h>
using namespace std;

void isKthBitSet(int n, int k)
{
	if (n & (1 << (k - 1)))
		cout << "SET";
	else
		cout << "NOT SET";
}

// Driver code
int main()
{
	int n = 700, k = 2;

	// Function call
	isKthBitSet(n, k);
	return 0;
}
