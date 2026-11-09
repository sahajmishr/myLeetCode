class Solution {
private: // copied  haah ... will so  it when i am out of this curse ...
  unordered_map<int, int> parent;
    int components = 0;

    int find(int x) {
        if (!parent.count(x)) {
            parent[x] = x;
            components++;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            components--; // Merging two components reduces total count by 1
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        for (const auto& stone : stones) {
            // Shift y-coordinate to avoid collision with x-coordinate values in the same map
            unite(stone[0], stone[1] + 10001); 
        }
        return stones.size() - components;
    }
};
