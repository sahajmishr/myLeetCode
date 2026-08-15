class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      
        int n = matrix.size() , temp ;
        // all because of eeshan the og smasher , red bass guy ;

        for(int i = 0 ; i<n;i++ ){
            for(int j = i ; j< n ;j++){
                //temp = matrix[i][j];
               swap( matrix[i][j] , matrix[j][i]);
                //matrix[j][i]= temp ;
            }
        }
        for(int r = 0 ; r<n ;r++){
           reverse(matrix[r].begin() , matrix[r].end());
            
        }
        
    }
};