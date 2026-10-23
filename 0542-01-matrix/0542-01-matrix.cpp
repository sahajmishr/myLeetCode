class Solution {// sometimes i feel i  like i am a genius and i reallly am ...
public:   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Fill 1s with a high value first so we can use min() safely without integer overflow
        int INF = m + n; 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 1) mat[i][j] = INF;
            }
        }

        // Pass 1: Check Top and Left neighbors
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                if (i > 0) mat[i][j] = min(mat[i][j], mat[i-1][j] + 1);
                if (j > 0) mat[i][j] = min(mat[i][j], mat[i][j-1] + 1);
            }
        } 

        // Pass 2: Check Bottom and Right neighbors
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 0) continue;
                if (i < m - 1) mat[i][j] = min(mat[i][j], mat[i+1][j] + 1);
                if (j < n - 1) mat[i][j] = min(mat[i][j], mat[i][j+1] + 1);
            }
        } 

        return mat; 
    }
};