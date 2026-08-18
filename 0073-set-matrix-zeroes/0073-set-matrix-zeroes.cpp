class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // hey i came back again ... how are you feeling mate ....
        // how aware are you mate ...
        int m = matrix.size();//rows or i j= constant
        int n  = matrix[0].size();// columnts or j i= constant 
        int col0 = 1 ;
        for(int i = 0 ; i<m;i++){
             if(matrix[i][0]==0){
                    col0= 0 ;
                } 
            for(int j= 1 ; j<n ; j++){
                 if(matrix[i][j]==0){
                  matrix[0][j]=0;
                  matrix[i][0]= 0 ; 

                }
            }
        }
        for(int k = 1 ; k<m ;k++){
            for(int l = 1 ; l<n ; l++){
                if(matrix[0][l]==0 || matrix[k][0]==0){
                    matrix[k][l]= 0 ;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int c= 0 ; c<n ; c++){
                matrix[0][c]= 0 ;
            }
        }
        if(col0 == 0 ){
            for(int r = 0 ; r<m ; r++){
                matrix[r][0]= 0 ; 
            }
        }
        
    }
};