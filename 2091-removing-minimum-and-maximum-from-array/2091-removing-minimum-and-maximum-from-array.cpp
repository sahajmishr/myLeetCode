class Solution { 
public: 
    int minimumDeletions(vector<int>& nums) { 
        int n = nums.size(); 
        if(n==1||n==2) return n ; 
        
        int max_val = INT_MIN , min_val = INT_MAX , maxind , minind ; 
        for(int i = 0 ; i < n ; i++) { 
            if (nums[i]>max_val){ 
                max_val = nums[i]; 
                maxind = i ; 
            }

            /// huuhhhh i did it it mate on my own  .... 
            if (nums[i]<min_val){ 
                min_val = nums[i]; 
                minind = i ; 
            }
        } 

        int fardist = max(minind , maxind ); 
        int closdist = min(minind , maxind); 
        
        
        int remove_from_front = fardist + 1;
        int remove_from_back = n - closdist;
        int remove_from_both = (closdist + 1) + (n - fardist);
        
       
        return min({remove_from_front, remove_from_back, remove_from_both});
    } 
};
