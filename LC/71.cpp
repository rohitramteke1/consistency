#include <bits/stdc++.h>
using namespace std;

string solve(string path) {

    stringstream ss(path);
    string token = "";
    stack<string> st;
    
    while ( getline(ss, token, '/') )
    {
        if(token == "/" or token == "") 
            continue;
        if( !st.empty() && token == ".") {
            st.pop();
        } else {
            st.push(token);
        }
    }

    string res = "";
    while( !st.empty() ) {
        res = res + st.top() + "/";
        st.pop();
    }

    return res;
}

int main()
{
    string path = "/home//foo/././";

    cout << solve(path) << endl;

    return 0;
}