class Solution {
private:
    void findCombinations(int idx, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (idx == candidates.size() || target < 0) {
            return;
        }
        // timepass just for the sterak ...
        
        current.push_back(candidates[idx]);
        findCombinations(idx, target - candidates[idx], candidates, current, result);
        current.pop_back();
        
        findCombinations(idx + 1, target, candidates, current, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>& current = *(new vector<int>()); 
        vector<int> path;
        findCombinations(0, target, candidates, path, result);
        return result;
    }
};
