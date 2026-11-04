using namespace std;

class Solution { // why do they make such songs haanhh ... why really why ...
public:
    void getid(vector<vector<int>>& grid, int number, int r, int c, vector<int>& sizeofisland) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1) {
            return;
        }
        
        grid[r][c] = number;
        sizeofisland[number]++;
        
        getid(grid, number, r + 1, c, sizeofisland);
        getid(grid, number, r - 1, c, sizeofisland);
        getid(grid, number, r, c + 1, sizeofisland);
        getid(grid, number, r, c - 1, sizeofisland);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int number = 2;
        
     
        vector<int> sizeofisland(n * m + 2, 0); 
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    getid(grid, number, i, j, sizeofisland);
                    number++;
                }
            }
        }  
        
        
        int maxsize = 0;
        for (int size : sizeofisland) {
            maxsize = max(maxsize, size);
        }
        
       
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                  
                    unordered_set<int> unique_neighbors;
                    
                  
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        
                       
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] > 1) {
                            unique_neighbors.insert(grid[ni][nj]);
                        }
                    }
                    
                 
                    int current_water_potential = 1;
                    for (int id : unique_neighbors) {
                        current_water_potential += sizeofisland[id];
                    }
                    
                  
                    maxsize = max(maxsize, current_water_potential);
                }
            }
        } 

        return maxsize;
    }
};