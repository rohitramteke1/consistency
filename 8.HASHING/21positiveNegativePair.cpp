// Link: https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1


// HashSet O(N) + O(N)
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        unordered_set<int> st;
        vector <int> result;
        
        for (int i=0; i<n; i++) {
            if ( st.find(-arr[i] ) != st.end() ) {

                result.push_back( -abs(arr[i]) );
                result.push_back( abs(arr[i]) );
            }
            st.insert(arr[i]);
        }
        
        return result;
    }
};

// HashMap O(N) + O(N)
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i){
            mp[abs(arr[i])]++;
            if(mp[abs(arr[i])] == 2){
                ans.push_back(-1*abs(arr[i]));
                ans.push_back(abs(arr[i]));
            }
        }
        
        if(ans.size() == 0){
            ans.push_back(0);
            return ans;
        }
        
        return ans;
    }
};