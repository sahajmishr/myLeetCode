class Solution {
public: // saat samandar paar mai ter peeche peeche aa gyi .. na rsta maloom na pata maloom 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res ;
        int n = prerequisites.size();
       
       vector<int> koidegree(numCourses , 0);
       queue<int> temp;
     vector<vector<int>> adj(numCourses);
     for(int i = 0 ; i< n ; i++){
         int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);
            koidegree[course]++;
        }
     
       for(int i  = 0 ; i< koidegree.size() ; i++){
        if(koidegree[i]==0 ){
         temp.push(i);
        }
     }
     while(!temp.empty()){
        int curr = temp.front();
        temp.pop();
        res.push_back(curr);
        for(int i = 0; i < adj[curr].size(); i++){
                int neighbor = adj[curr][i]; 
                koidegree[neighbor]--;       
                if(koidegree[neighbor] == 0){
                    temp.push(neighbor);
                }
            }
        }
       if(res.size() != numCourses) return {};

       return res ; 
    }
};