int totdiv(vector<int>& nums, int divi){
    long long td = 0 ;
    for(int i = 0 ; i< nums.size(); i++){
        td+= ceil((double )nums[i]/divi);
    }
    return td;
}
// i am the one to get me to paradise 
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = *max_element(nums.begin(), nums.end());
        int  mn = 1 ,  mid = 0 , ans = 0;
         
        while(mn<=mx){
            mid= (mn+mx)/2;
            if(totdiv(nums , mid)<= threshold){
                ans= mid ;
                mx = mid-1;
            }else mn = mid+1 ;
        }
        return ans ;


    }
};