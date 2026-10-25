class Solution {
public:// i really need to think i need to be back and do it .. again  or else i can loose the field .. ehich i dont want so i need to work hard and re win the game yrr i wil i will i will only i will 
bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
      
        if (visited[node] == 1) return true;
       
        if (visited[node] == 2) return false;
        

        visited[node] = 1;
        
      
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited)) {
                return true; 
            }
        }
        
        visited[node] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }
        
       
        vector<int> visited(numCourses, 0);
        
       
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, adj, visited)) {
                    return false; 
                }
            }
        }
        
        return true; 
    }
};