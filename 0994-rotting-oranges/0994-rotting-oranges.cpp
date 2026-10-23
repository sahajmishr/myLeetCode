class Solution {
public: // binte dil misereya me ... mehkash labon pe aane lagin hai pyasi kurbate .. gehrat juban thikane lagi sari furkatein ...
    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size() ;
       int n = grid[0].size();
       int freshOranges = 0 ;
       int minute = 0;
       queue<pair<int , int >> q ;
        for(int i = 0 ; i< m  ; i ++){
         for(int j = 0 ; j< n ; j++){
            if(grid[i][j]==2){
                q.push({i , j});
            }else if( grid[i][j]==1){
              freshOranges ++ ;
            }
         }
        } 

        while(!q.empty()&& freshOranges> 0){
            int batch = q.size();
            for(int i = 0 ; i< batch ; i++){
              auto [a , b ]  = q.front();
              q.pop();
              if(a!=0 &&grid[a-1][b]==1){
                grid[a-1][b]= 2;
                q.push({a-1 , b});
                freshOranges--;
              }
              if(b!=0 &&grid[a][b-1]==1){
                grid[a][b-1]= 2;
                q.push({a , b-1});
                freshOranges--;
              }
              if(a!=m-1 &&grid[a+1][b]==1){
                grid[a+1][b]= 2;
                q.push({a+1 , b});
                freshOranges--;
              }
              if(b!=n-1 &&grid[a][b+1]==1){
                grid[a][b+1]= 2;
                q.push({a , b+1});
                freshOranges--;
              }
            }

            minute++ ;
        }

       if(freshOranges != 0) return -1 ;
       return minute ;
    }
};