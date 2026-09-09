class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int left = 0, tolerate0 = k; 

        for(int right = 0; right < n; right++){ 
            if(nums[right] == 0){ 
                tolerate0--;
            }

// lets see .... i will kill it i am so angry ....
            if(tolerate0 < 0) {
                if(nums[left] == 0) {
                    tolerate0++;
                }
                left++;
            }
        } 
        
        return n - left; 
    } 
};
