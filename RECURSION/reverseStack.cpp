#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void reverse(stack<int> &s) {
    if(s.empty()) return;
    st.push(s.top());
    s.pop();
    reverse(s);
}

int main()
{
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    reverse(s);
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    

    return 0;
}