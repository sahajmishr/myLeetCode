class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        /// hey mate you triggered the wrong one ...... the wrong wrong version of me ;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0 , bottom = m-1 ; 
        int left = 0 , right = n-1 ; 
        vector<int> ot;
        while(left<=right&& top<=bottom){
        for(int i = left ; i<= right ; i++){
            ot.emplace_back(matrix[top][i]);
        }
        top++ ;
    
        for(int i = top ; i <= bottom ; i++){
            ot.emplace_back(matrix[i][right]);
        }
        right-- ;
        
        if(top<= bottom){
        for(int i = right ;i >= left ; i--){
            ot.emplace_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<= right){
        for(int i = bottom ; i >= top ; i --){
            ot.emplace_back(matrix[i][left]);
        }
        left++ ;
        }
        
        }
        return ot ;
    }
};