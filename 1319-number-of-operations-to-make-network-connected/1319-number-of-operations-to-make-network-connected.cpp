class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            components--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
       int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        DSU dsu(n);
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }
        return dsu.components - 1;
    }
};
