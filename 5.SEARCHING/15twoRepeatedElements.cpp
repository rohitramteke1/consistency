class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> pair;
        int MX = n + 1;
        
        for (int i=0; i<n+2; i++) 
        {
            int index = arr[i];
            arr[index % MX] += MX;
        }
        
        // now we've the elements which appear more than 1 times
        for (int i=0; i<n+2; i++) {
            if (arr[i] / MX > 1) 
                pair.push_back( i );
        } 
        // now we get the original array
        for (int i=0; i<n+2; i++) {
            arr[i] = arr[i] % MX;
        }

        int fir_counter = 0;
        int sec_counter = 0;

        // now we want the order of that elements, now just check linearly
        for (int i=0; i<n+2; i++) {
            if ( pair[0] == arr[i] )
                fir_counter++;
                
            if (fir_counter == 2)
                return { pair[0], pair[1] };
        
            if ( pair[1] == arr[i] )
                sec_counter++;
        
            if (sec_counter == 2)
                return { pair[1], pair[0] };
        
        }
        
        return { -1, -1 };
    }
};

// Link : https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1