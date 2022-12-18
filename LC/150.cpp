// evaluate reverse polish notation
// aka Postfix notation

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<long> st;
    for (auto s: tokens) {
        if( s == "+" || s == "-" || s == "*" || s == "/") {
            long a = st.top(); st.pop();
            long b = st.top(); st.pop();
            char _operator = s[0]; // operator is reserved keyword in cpp
            switch(_operator) {
                case '+' : st.push(b + a); break;
                case '-' : st.push(b - a); break;
                case '*' : st.push(b * a); break;
                case '/' : st.push(b / a); break;
            }
        }
        else {
            st.push(stoi(s));
        }
    }
    return st.top();
}

int main()
{
    vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(v) << endl;
    return 0;
}