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
   vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAccIdx;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccIdx.find(email) == emailToAccIdx.end()) {
                    emailToAccIdx[email] = i;
                } else {
                    dsu.unite(i, emailToAccIdx[email]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedEmails;
        for (auto const& [email, idx] : emailToAccIdx) {
            int root = dsu.find(idx);
            mergedEmails[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : mergedEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account = {accounts[root][0]};
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }

        return result;
    }
};