class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int req , reqi , n = nums.size();
        req = (n/3) ;
        vector<int> elem ;
        if(n==1){
            return nums ;
        }
        if(n<= 2&& nums[0]!=nums[1]){
            return nums ;
        }else if(n<=2 && nums[0]==nums[1]){
          elem.emplace_back(nums[0]); 
            return elem ;
        }
        
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i <n ; i++){
            reqi = i+req ;
            if(find(elem.begin(), elem.end() , nums[i]) == elem.end()&&reqi<n){
               if(nums[i] == nums[reqi]){
               elem.emplace_back(nums[i]);
               }
            }
        }
       return elem ; 
    }
};