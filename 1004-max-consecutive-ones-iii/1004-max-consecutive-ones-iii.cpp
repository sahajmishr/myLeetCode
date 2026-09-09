class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 
        int n = nums.size(); 
        int count1 = 0 ; 
        int maxcount = 0 , left = 0 , tolerate0 = k ; 
        
        for(int right = 0 ; right < n ; right++ ){ 
            if(nums[right] == 0){ 
                if(tolerate0 > 0){ 
                    tolerate0--; 
                } else if (tolerate0 == 0 ){ 
                    
                    count1 = (right - left); 
                    maxcount = max(maxcount , count1); 
                    
                   
                    while (nums[left] != 0) {
                        left++;
                    }
                    left++; 
                } 
            } 
          
            maxcount = max(maxcount, right - left + 1);
        } 
        return maxcount; 
    } 
};
