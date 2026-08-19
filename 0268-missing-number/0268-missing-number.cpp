class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0 , sumt  , n= nums.size();
        for(int i = 0 ; i<nums.size(); i++){
            sum+=nums[i];
        }
        sumt = (n*(n+1))/2;
        
        return sumt-sum ;
    }
};