class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxcount = 0;
        int left = 0; 
        set<char> mp;
        // now sugar momma really need something ...
        for (int right = 0; right < n; right++) {
           
            while (mp.contains(s[right])) {
                mp.erase(s[left]);
                left++;
            }
            
          
            mp.insert(s[right]);
            maxcount = max(maxcount, right - left + 1);
        }

       return maxcount; 
    }
};
