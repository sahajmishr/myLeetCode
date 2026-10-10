class Solution {
public:// it reminded me of something ... made me feel heavy ... i dont want this feeling though .. hate this question 

    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_jump) return false;
            max_jump = max(max_jump, i + nums[i]);
        }
        return true;  
    }
};
