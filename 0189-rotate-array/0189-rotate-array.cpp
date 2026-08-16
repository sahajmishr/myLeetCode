class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kr = k%n  , last = n-1 , c= 0 ;
        for(int i = 0 ; i <n/2 ;i++){
            swap(nums[i] , nums[last-i]);
        }
        for(int j = 0 ; j<kr/2; j++){
            swap(nums[j] , nums[(kr-1)-j]);

        }
       while(kr <last){
        swap(nums[kr] , nums[last]);
        kr++ ;
        last -- ;

       }
       
        
    }
};