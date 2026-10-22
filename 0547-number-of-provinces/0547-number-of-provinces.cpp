class Solution {// kindaa need to do it hard way ..need to revise .
public: void modDfs(int i ,vector<vector<int>>& isConnected , vector<int>& visited  ){
   visited[i] = 1;
   for(int j = 0 ; j< isConnected.size()  ; j++){
    if(isConnected[i][j]== 1&& !visited[j]){
      modDfs(j , isConnected , visited);
    }
   }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0 ;
       vector<int> visited (isConnected.size() , 0) ;
      for(int i = 0 ; i < isConnected.size() ; i++){
        if(visited[i] == 0){
            count++ ;
            modDfs(i , isConnected , visited);
        }
      }
      return count ;
    }
};