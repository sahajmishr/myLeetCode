class Solution { // maine dekh ke kiya hai yrr .. 
public: bool dfs(int node, int col, vector<int>& color, const vector<vector<int>>& graph) {
        color[node] = col; // Assign the current color to the node

        for (int neighbor : graph[node]) {
            // If the neighbor is not colored yet, recursively color it with the opposite color (1 - col)
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - col, color, graph)) {
                    return false;
                }
            }
            // If the neighbor already has the same color, it's not bipartite
            else if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means the node is uncolored

        // Loop through all nodes to handle disconnected graph components
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};