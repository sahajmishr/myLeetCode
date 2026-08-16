class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int  n = nums.size() , count = 0 , c1 = 0 ;
        for(int i = 0 ; i <n ; i++){
            if(nums[i]==1){
                c1 ++;
                if(count<c1){
                    count = c1 ;
                }
            }else {
                c1=0 ;
            }
        }
        return count ;
        
    }
};