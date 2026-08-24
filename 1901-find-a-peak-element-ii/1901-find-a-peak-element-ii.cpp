class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

         /// yeah be gone....
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            
            bool leftIsLarger  = (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool rightIsLarger = (mid < n - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!leftIsLarger && !rightIsLarger) {
               
                return {maxRow, mid};
            } else if (leftIsLarger) {
               
                high = mid - 1;
            } else {
            
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
