class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        string res = "";
        int carry = 0;
        int i = X.length() - 1;
        int j = Y.length() - 1;
        
        while (i >= 0 || j >= 0 || carry ) {
            int a = 0, b = 0;
            if (i >= 0) a = X[i--] - '0';
            if (j >= 0) b = Y[j--] - '0';
            
            int digit = a + b + carry;
            carry = digit / 10;
            res.push_back( (digit % 10) + '0');
        }
    
        reverse(res.begin(), res.end());
        
        size_t pos = res.find_first_not_of('0');
        if (pos == string::npos)
            return "0";
        else
            return res.substr(pos);
    }
};