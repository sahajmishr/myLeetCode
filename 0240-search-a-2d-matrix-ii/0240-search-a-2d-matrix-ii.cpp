class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // kinda mixed 
        int row = 0 , col = matrix[0].size()-1 , curr ;
        while(row<matrix.size()&& col>= 0){
           curr  = matrix[row][col];
           if(curr == target){
            return true ;
           }else if(curr>target ){
            col--;
           }else row++ ;
        }
        return false ;
    }
};