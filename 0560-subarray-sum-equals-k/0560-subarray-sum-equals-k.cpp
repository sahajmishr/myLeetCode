class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int , int > mp ;
        int n = nums.size() , count = 0 , sum = 0 , past_sum  ;
        mp[0] = 1;
        for(int i = 0 ; i<n ; i++){
            sum+= nums[i];
            past_sum = sum - k ;
            if(mp.find(past_sum)!= mp.end()){
                count += mp[past_sum];
            }
             mp[sum]++; 
        }
        return count ;
    
    }
};