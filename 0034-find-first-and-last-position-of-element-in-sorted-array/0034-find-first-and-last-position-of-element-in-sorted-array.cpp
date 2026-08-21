class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() , first = -1 , end = -1 ;
        int low = 0 , high = n-1 , mid=0 ;
        vector<int> ot ;
        while(low<= high){
            mid= low + (high-low)/2;

            if(nums[mid] == target){
                first = mid ;
                high = mid-1;
            }else if (nums[mid]<target){
                low = mid+1 ;
            } else high = mid-1 ;
        } 

        low = 0, high = n-1;
        while(low<= high){
            mid= low + (high-low)/2;

            if(nums[mid] == target){
                end = mid ;
                low = mid+1;
            }else if (nums[mid]<target){
                low = mid+1 ;
            } else high = mid-1 ;
        } 

        ot.push_back(first);
        ot.push_back(end);

        return ot ;
    }
};
