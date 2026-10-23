class Solution {
public: // keep sinking those who are connected and count those wicch are not .... asa kooda 
    void sinkgrid(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        sinkgrid(grid, i - 1, j);
        sinkgrid(grid, i + 1, j);
        sinkgrid(grid, i, j + 1);
        sinkgrid(grid, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

       
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                sinkgrid(grid, i, 0);
            }
            if (grid[i][n - 1] == 1) {
                sinkgrid(grid, i, n - 1);
            }
        }

      
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                sinkgrid(grid, 0, j);
            }
            if (grid[m - 1][j] == 1) {
                sinkgrid(grid, m - 1, j);
            }
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
