#include <iostream>
using namespace std;

void printNbonacci(int n, int m) {
    int a[m] = { 0 };
    a[n - 1] = 1;
    int sum = 1;

    for (int i = n; i < m; i++) {
        sum += a[i - n] - a[i];
        a[i] = sum;
    }

    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n, m;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the number of terms to print: ";
    cin >> m;

    printNbonacci(n, m);
    cout << endl;

    return 0;
}
