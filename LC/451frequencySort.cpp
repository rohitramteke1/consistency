#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    
    vector<int> v1(62, 0);
    vector<int> v2(62, 0);
    vector< pair<int, int> > p;

    for (int i = 0; i < 62; i++) v2[i] = i;
    
    for (int i = 0; i < 62; i++) 
        p.emplace_back( make_pair(v1[i], v2[i]) );
    
    for (auto &&i : s)
        if(i >= 'a' && i <= 'z')
            p[i-'a'].first += 1;
        
        else if(i >= 'A' && i <= 'Z')
            p[i-'A'+26].first += 1;
        
        else if(i >= '0' && i <= '9' )
            p[i-'0'+52].first += 1;
    

    sort(p.begin(), p.end(), greater<>());

    // for (auto &&i : p)
    // {
    //     if(i.second >= 0 && i.second <= 25) {
    //         cout << i.first << ' ' << char(i.second+'a') << endl;
    //     } 
    //     else if(i.second >= 26 && i.second <= 51) {
    //         cout << i.first << ' ' << char(i.second-26+'A') << endl;
    //     }
    // }
    
    s = "";
    for (auto &&i : p)
        if(i.second >= 0 && i.second <= 25)
            while(i.first--) s += char(i.second+'a');

        else if(i.second >= 26 && i.second <= 51)
            while(i.first--) s += char(i.second-26+'A');

        else if(i.second >= 52 && i.second <= 61) 
            while(i.first--) s += char(i.second-52+'0'); 

    return s;
}

int main()
{
    cout << frequencySort("Cool2226Boys");
    
    return 0;
}