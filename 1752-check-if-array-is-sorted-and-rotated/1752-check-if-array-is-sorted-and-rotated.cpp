class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() , max , count = 0  , ind , sec_max ;
        for(int i = 1; i<n  ; i++){
            if(nums[i]<nums[i-1]){
                max = nums[i-1];
                sec_max = nums[i];
                 ind = i;
                 count++ ;
                 break ;
            }
            if(i== n-1&& count == 0 ){
                return true ;
            }

        }
        for(int j = ind ; j<n ; j++){
            if(nums[j]>max|| nums[j]< sec_max|| nums[j]>nums[0]){
                return false ;
            }
            sec_max = nums[j];
            
        }
      return true ;
        
    }
};