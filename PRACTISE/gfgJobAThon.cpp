#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
bool prime[N];

void prime_array(int n)
{
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j < N; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
}

int no_of_bots(string &s)
{
    unordered_map<char, int> hash;
    int bots = 0;
    // int j = 1;
    // int ct = 1;
    // int len = s.length();
    // while (j < len)
    // {
    //     hash[s[j]]++;
    //     if (s[i] != s[j])
    //     {
    //         i++;
    //         ct++;
    //         if (j % 2 == 0)
    //         {
    //             bots += prime[hash.size()];
    //         }
    //     }
    //     j++;
    // }
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
        if(i%2 == 0) {
            if(prime[hash.size()])
            {
                bots++;
            }
        }
    }
    
    return bots;
}

int main()
{
    for (int i = 2; i < N; i++)
        prime[i] = 1;

    prime_array(N);

    string s = "qsjbmbiwbtuctqxznkvuspszjw";
    cout << no_of_bots(s) << endl;

    return 0;
}