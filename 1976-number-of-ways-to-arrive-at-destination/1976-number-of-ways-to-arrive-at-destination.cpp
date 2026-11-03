class Solution { // toure la da vida vida ..... 
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    //  int n = roads.size();
     vector<pair<int , long long>> adj[n];
     for(auto it : roads){
        adj[it[0]].push_back({it[1] , it[2]});
        adj[it[1]].push_back({it[0] , it[2]});
     }
     priority_queue<pair<long long , int> ,  vector<pair<long long , int >> , greater <pair <long long , int >>>  pq ;
     vector<long long> dist(n , LLONG_MAX);
     vector<int> ways(n , 0);
     dist[0] = 0 ;
     ways [0] = 1 ;
     pq.push({0 , 0 });
     int mod = (int)(1e9+7);
     while(!pq.empty()){
     
     long long dis  = pq.top().first ;
      int node = pq.top().second ;
      pq.pop();
     for(auto it : adj[node]){
       int adjnode = it.first ;
       long long edw = it.second ;
      if(edw+ dis < dist[adjnode]){
        dist[adjnode] = edw+ dis ;
        ways[adjnode]  = ways[node];
        pq.push({dis+edw , adjnode});
      } 
      else if(edw + dis == dist[adjnode]){
        ways[adjnode] = (ways[node]+ways[adjnode])%mod;
      }

     }
     }

     return (ways[n-1])%mod;

     
     
    }
};