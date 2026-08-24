class Solution {
public:
 int findRow(vector<vector<int>>& matrix, int target ){
        int n = matrix[0].size() ,ans =0 , mid;
        int low = 0  , high = matrix.size()-1;
        while(low<= high){
           mid = (low+high)/2 ;
            if(matrix[mid][n-1]>=target){
                high = mid-1 ;
                ans = mid ;
            }else {
                low = mid+1 ;
            }
            
        }
        return ans ;
        
      } 
      // if it runs will be on my own ... 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int low = 0 , high = matrix[0].size()-1  , mid ;
     int row = findRow(matrix , target ) ;
     while(low<= high ){
        mid = low + (high - low) / 2; 
        if(matrix[row][mid]==target){
            return true ;
        }else if (matrix[row][mid]>target){
            high = mid-1 ;
        }else low = mid+1 ;
        
     }
     return false ;
     
    }
};