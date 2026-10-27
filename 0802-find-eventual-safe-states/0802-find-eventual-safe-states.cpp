class Solution {
public:// haa tum bilkul vaisi hp .. jaisa maine socha tha .. na kasme ho na rasme ho . na shikwe ho na vade . ek surat bholi bhali ho do naina sidhe sadhe ....
// doing it for the cause ...
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n) ; 
        vector<int> res ;
        vector<int> indegree(n , 0);
        queue<int> tempo ;
        for(int i = 0 ; i< graph.size() ; i++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i = 0 ; i< indegree.size(); i++){
            if(indegree[i]==0){
                tempo.push(i);
                
            }
        }
        while(!tempo.empty()){
            auto curr = tempo.front();
            res.push_back(curr);
            tempo.pop();
            for(auto it : rev[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    tempo.push(it);
                }
            }

        }
        sort(res.begin() , res.end());
        return res ;
    
    }
};