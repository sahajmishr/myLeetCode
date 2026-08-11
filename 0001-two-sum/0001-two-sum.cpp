class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low , high, n  ; 
        low = 0 ;
        high = 1;
        n = nums.size();
        vector<int> sol ;
        while (low < n){
           if (nums[low]+ nums[high] == target ){
            sol.emplace_back(low);
            sol.emplace_back(high); 
            return sol ;
           } 
           high ++ ;
           if (high >= n){
            low ++ ;
            high = low+1 ;
           }
        }
        return sol ;
        
    }
};