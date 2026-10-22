class Solution {// maine tera naam dil rakh diya . lets see if will run or not 
public: void fillkro(vector<vector<int>>& grid, int i, int j, int color , int strt){
    int m   = grid.size();
    int n = grid[0].size();
     
     if(i< 0 || i >= m || j<0|| j>= n|| grid[i][j] != strt ) {
        return ;
     }
     grid[i][j]= color ;
     fillkro(grid , i-1 , j , color , strt);
     fillkro(grid , i+1 , j , color , strt);
     fillkro(grid , i , j+1 , color , strt);
     fillkro(grid , i , j-1 , color , strt);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
         int strt = image[sr][sc] ;
         if(strt == color) return image ;
        fillkro(image , sr , sc , color , strt);
        return image ;
    }
};