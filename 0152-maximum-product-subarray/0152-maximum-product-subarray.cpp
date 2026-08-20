class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // as it is going to be the last race i am feeling really heavy but no problem i am a man and i can achive anything i want just need will power ... 
       // and dont worry i will still visit you mate ... 
       int n = nums.size();
       int pre = 1 , suf = 1 , ans = INT_MIN ;
       for(int i = 0 ; i<n ; i++ ){
        if(pre == 0 ) pre = 1;
        if(suf ==0 ) suf = 1 ;
         pre *= nums[i];
         suf *= nums[n-i-1];
         ans = max(ans , max(pre,suf));

       } 
       return ans ;
    }
};