class Solution {
public: // doing for teh cause ...
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return ans;

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> visited;
        queue<string> q;

        q.push(beginWord);
        visited[beginWord] = 0;

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            string temp = curr;
            for (int i = 0; i < temp.size(); i++) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.find(temp) != dict.end()) {
                        if (visited.find(temp) == visited.end()) {
                            visited[temp] = visited[curr] + 1;
                            q.push(temp);
                            adj[temp].push_back(curr);
                        } else if (visited[temp] == visited[curr] + 1) {
                            adj[temp].push_back(curr);
                        }
                        if (temp == endWord) found = true;
                    }
                }
                temp[i] = orig;
            }
        }

        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, adj, path, ans);
        }

        return ans;
    }

private:
    void dfs(string curr, string& beginWord, unordered_map<string, vector<string>>& adj, vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> copy = path;
            reverse(copy.begin(), copy.end());
            ans.push_back(copy);
            return;
        }
        for (auto& prev : adj[curr]) {
            path.push_back(prev);
            dfs(prev, beginWord, adj, path, ans);
            path.pop_back();
        }
    }
};