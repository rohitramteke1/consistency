// Reversing the equation
// Link: https://practice.geeksforgeeks.org/problems/reversing-the-equation2205/1

class Solution
{
    bool isArithemeticOperator(char ch) {
        return ((ch == '+') or (ch == '-') 
            or (ch == '*') or (ch == '/'));
    }
  public:
    string reverseEqn (string s)
    {
        string equation = "", temp = "";
        int n = s.length();
        int end = 0, start = 0;
        
        for ( ; end < n; ++end ) {
            
            if ( isArithemeticOperator(s[end]) ) {
                string temp = s.substr(start, end - start);
                start = end + 1;
                equation.insert( 0, s[end] + temp );
            }
        }
        temp = s.substr(start, end - start);
        equation.insert( 0, temp );
        return equation;
    }
};