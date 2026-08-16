class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() , n1 = 0 , nz = 0 ; 
        while(nz<n){
            if(nums[nz]!=0){
                swap(nums[nz],nums[n1]);
                nz++;
                n1++;
            }else {
                nz++ ;
            }
            
           
        }
        
    }
};