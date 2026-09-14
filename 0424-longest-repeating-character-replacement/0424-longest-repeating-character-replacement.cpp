class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.size();
       int r = 0 , l = 0 , maxlen = 0 ;  
       int counts[26] = {0};            
       int max_freq = 0;                 
// i dont know.... rukja means what ...
       while(r < n) {
        counts[s[r] - 'A']++;                             
        max_freq = max(max_freq, counts[s[r] - 'A']);     
        
         
        if ((r - l + 1) - max_freq > k) { 
            counts[s[l] - 'A']--;                         
            l++;
        }
        
        maxlen = max(maxlen, r - l + 1);
        r++;
       } 
       return maxlen ;
    }
};