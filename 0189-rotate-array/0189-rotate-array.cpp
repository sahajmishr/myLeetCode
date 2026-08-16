class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kr = k%n ;
         reverse(nums.begin() , nums.end());
         reverse(nums.begin(), nums.begin()+kr);
         reverse(nums.begin()+kr , nums.end());
       
        
    }
};