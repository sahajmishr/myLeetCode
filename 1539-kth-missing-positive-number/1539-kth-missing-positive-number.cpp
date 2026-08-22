

class Solution {
public:
      // plss dont suck this time 
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int mxind =-1  , mnind = -1 ;
        if(arr[n-1]==n) return arr[n-1]+k;

        for(int i =0 ; i<n ;i++){
             int missing = arr[i] - (i + 1); 
            
           
            if(missing >= k) {
                return i + k;
            }
        }
       return n+k;
    }
};