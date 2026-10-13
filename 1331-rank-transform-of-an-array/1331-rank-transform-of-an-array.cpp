class Solution {
public: // hashhh it crossed the test cases yrrr 
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return arr ;
      priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int, int>>> pq ;
      for (int i = 0 ; i< arr.size() ; i++){
       pq.push({arr[i], i});
      }  
     int prio = 1 ;
      pair<int , int > root =  pq.top();
      arr[root.second] = prio ;
      pq.pop();
     while(!pq.empty()){
      if(root.first == pq.top().first ){
        arr[pq.top().second] = prio ;
        pq.pop();
      }else{
        prio++ ;
        root = pq.top();
        pq.pop();
        arr[root.second] = prio ;

      }
    

      
     }
     return arr ;
    
    }
};