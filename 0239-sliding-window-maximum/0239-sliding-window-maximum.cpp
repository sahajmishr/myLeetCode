class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int> ans ; 
       // size again ??? i am really hell for it .. but dont know it feels that i can make it .. today 
       deque<int> dq ;
       for(int i = 0 ; i<n ; i++){
         if(!dq.empty()&& dq.front() <= i - k) {
            dq.pop_front() ;
         }
         while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
         }
         dq.push_back(i);
         if(i>= k-1){
          ans.push_back(nums[dq.front()]);
         }
        } 
        return ans ;
    }
};