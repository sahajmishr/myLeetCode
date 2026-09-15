class Solution {
public:
int findless(vector<int>& nums, int goal){
    if(goal<0) return 0 ;
    // waah bhai dimaag hona bhot jaruri hai varna chutiya he kat ta rhega ....hmmmmmmmmmmmmm
    int n = nums.size() ; 
    int  r = 0 , l = 0 , sum = 0 , count = 0 ;
    while(r<n){
        sum+= nums[r]%2 ;
        while(sum>goal){
        sum-=nums[l]%2;
        l++;
        }
        count+= (r-l)+1 ;
        r++;
        
    }
    return count ;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       return findless(nums , k) - findless(nums , k-1); 
    }
};