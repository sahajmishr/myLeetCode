class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size(); 
        int num = 1 ;
        for(int i = 0 ; i<n ;i++){
            if(nums[i] <=0) continue ;
            if(nums[i] == num){
                num++ ;
            }else return num ;

           while(i<n-1&& nums[i]==nums[i+1])  i++ ; 
        }
        return num;
    }
};