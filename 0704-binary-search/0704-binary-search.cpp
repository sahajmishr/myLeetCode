class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // i am not happy with my work .. i like ot do it but i hate the way i am performinhg into it ...
        int mid , low = 0 , high = n-1 ;
        while(low<=high){
            mid = (low+high)/2;
        if (nums[mid]==target){
            return mid;
        }else if(target>nums[mid]){
            low = mid+1 ;
        }else high = mid-1 ;
        }

        return -1 ;
        
    }
};