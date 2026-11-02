class Solution {
public: // kind off similar to running dijkshtra to each node with pq and efforts 
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        efforts[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int currentEffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            
            if (r == rows - 1 && c == cols - 1) {
                return currentEffort;
            }
            
            if (currentEffort > efforts[r][c]) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextEffort = max(currentEffort, abs(heights[r][c] - heights[nr][nc]));
                    
                    if (nextEffort < efforts[nr][nc]) {
                        efforts[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }
        
        return 0;
    }
};