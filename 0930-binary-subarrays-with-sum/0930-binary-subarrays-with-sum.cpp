class Solution {
public:
// but its just one day and   i can do it surely .. yes i can man yees i will man .. yes i am man 
int findless(vector<int>& nums, int goal){
    if(goal<0) return 0 ;
    int n = nums.size() ; 
    int  r = 0 , l = 0 , sum = 0 , count = 0 ;
    while(r<n){
        sum+= nums[r] ;
        while(sum>goal){
        sum-=nums[l];
        l++;
        }
        count+= (r-l)+1 ;
        r++;
        
    }
    return count ;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return findless(nums , goal) - findless(nums , goal-1) ; 
    }
};