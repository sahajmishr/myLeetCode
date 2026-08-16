class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k= 0   , on= 0  , nex= 0  ;
        for(int i = 0 ;i<n-1 ; i++){
            if(nums[i]==nums[i+1]){
                nums[i]= -101 ;
                k++;
            }
        }
        for(int j = 0 ; j <n ; j++){
            if(nums[j]!= -101){
                swap(nums[j] , nums[on]);
                on++;
            }
            nex++;

        }
        return (n-k);
        
    }
};