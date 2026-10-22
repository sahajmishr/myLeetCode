class Solution { // dil tod ke hasti ho mera .. wafaye mere baad krogi 
public: void sinkgrid(vector<vector<char>>& grid , int i , int j){
     int m = grid.size();
     int n = grid[0].size(); 
     if(i< 0 || i >= m || j<0|| j>= n|| grid[i][j]=='0' ) {
        return ;
     }
     grid[i][j]= '0';
     sinkgrid(grid , i-1 , j);
     sinkgrid(grid , i+1 , j);
     sinkgrid(grid , i , j+1);
     sinkgrid(grid , i , j-1);
}
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size(); 
      int count = 0 ;
      for(int i = 0 ; i< m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(grid[i][j] == '1'){
                sinkgrid(grid , i , j );
                count++ ;
            }
        }
      } 
      return count ;
    }
};