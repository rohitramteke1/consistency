#include <iostream>
#include <string>

using namespace std;


// Brute Force O(n * (2^n))
string subseq = "";

bool generateSubsets(const string &str, string &current, int index = 0) {
    int n = str.length();

    // Base case: when index reaches the end of the string
    if (index == n) {
        if (current == subseq)
            return 1;
        return 0;
    }

    current.push_back(str[index]);
    // Recursive case 1: include the current character
    bool take = generateSubsets(str, current, index + 1);

    current.pop_back();
    // Recursive case 2: exclude the current character
    bool notake = generateSubsets(str, current, index + 1);

    return take || notake;
}

// O(n + m) + O(1)
bool optimal(const string &str, const string &sub) {
    int j = 0;

    int m = sub.length();
    int n = str.length();

    for (int i=0; i<n && j<m; i++) {
        if (str[i] == sub[j])
            j++;
    }

    return (j == m);
}

int main() {
    string str = "BATMAN";
    subseq = "BAT";
    string curr = "";

    cout << generateSubsets(str, curr, 0) << endl;

    cout << optimal(str, subseq) << endl;

    return 0;
}
