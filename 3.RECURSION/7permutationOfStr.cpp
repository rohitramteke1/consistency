#include <iostream>
using namespace std;

void permutationOfString(string s, int index) {

    // base condition
    if(index >= s.length())
    {
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        // give the chance to each and every char
        swap(s[i], s[index]);

        // repeat the process
        permutationOfString(s, index + 1);

        // backatrack
        swap(s[i], s[index]);
    }
}

int main()
{
    string s = "abc";

    permutationOfString(s, 0);
    
    return 0;
}