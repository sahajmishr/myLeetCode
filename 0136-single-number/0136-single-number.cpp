class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size()  ;
        int number ;
        sort(nums.begin() , nums.end());
        if(n==1){
            return nums[0];
        }
        for(int i = 0 ; i<n ;i+=2){
            if(nums[i]!=nums[i+1]){
                number = nums[i];
                return number ;
            }
        }
       return number ; 
    }
};