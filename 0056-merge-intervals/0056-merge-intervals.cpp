class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ins) {

        if (ins.empty()) return {};
        vector<vector<int>> ots;

        sort(ins.begin(), ins.end());
        
        int s = ins[0][0];
        int e = ins[0][1];
        
        for (int i = 1; i < ins.size(); i++) {
            if (ins[i][0] <= e) {
                e = max(e, ins[i][1]);

            } else {
                ots.emplace_back(vector<int>{s, e});
                s = ins[i][0];
                e = ins[i][1];
            }
        }
        ots.emplace_back(vector<int>{s, e});
        return ots;
    }
};