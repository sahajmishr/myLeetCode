class Solution {
public:// i dont kmnow how k-1 worked ..
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq ;
        pq.push(nums[0]);
      for(int i = 1 ; i < nums.size(); i++){
         
        pq.push(nums[i]);
          
      } 
      for(int i = 0 ; i<k-1 ; i++){
        pq.pop();
      } 
      return pq.top();
    }
};