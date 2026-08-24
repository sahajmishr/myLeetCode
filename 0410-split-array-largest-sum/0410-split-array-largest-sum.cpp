class Solution {
public:
  int giveMeSum(vector<int>& nums, int cap){
    int sum = 0 , ks =1 ;
    for(int i = 0 ; i<nums.size() ; i++){
        
        if(sum+nums[i] > cap){
            ks ++ ;
            sum = nums[i];
        }else {
            sum += nums[i];
        }
        
    }
    return ks ;
  }
    int splitArray(vector<int>& nums, int k) {
     // ava ava ta batayi toha ... hehehehe don by meeeee  
     int high = accumulate(nums.begin() , nums.end() , 0 ) ;
     int low = *max_element(nums.begin(), nums.end());
     int ans = 0  , mid = 0 , pos = 0;
     while(low<= high){
          mid = (low+high)/2 ;
          pos = giveMeSum(nums , mid);
        if(pos>k){
            low = mid+1 ;
        }else {
            
            high = mid-1;
        }
     }
     return low ;
     
    }
};