class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // i cant have it aymore but its gonna be max's last race at home ..it feels heavy 
        map<int , int > mp;
        int n = nums.size() , c1 =0, cl=0;
        if(k==nums.size()){
            sort(nums.begin(), nums.end() , greater<int>() );
            return nums[0];
        }else if (nums[0]==nums[n-1]&& k!=1){
            return -1 ;
        }
        
       if (k == 1) {
      for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
      }
    
      int ans = -1;
      for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        if (it->second == 1) {
            ans = it->first;
            break;
        }
      }
     return ans;
}
         int first = nums[0];
         int last = nums[n-1];
        for(int i= 1;i<n-1;i++){
        if(nums[i]==first){
            c1++;
        }else if (nums[i]==last){
            cl++;
        }

        }
        if(c1==0 &&cl == 0){
            return max(first , last);
        }else if(c1==0&&cl!=0){
            return first ;
        }else if(c1!=0 &&cl==0){
            return last ;
        }else{
            return -1 ;
        }
        
    }
};