class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
      int n = strs.size();
      // i dont belive i did it ...
      string match = strs[0];
      for(int i = 1 ; i< n ; i++){
      if(match[0] != strs[i][0]) return "";
      int j = 0 ;
      string tempmatch = "";
      while(match[j]== strs[i][j]&& j<match.size() && j<strs[i].size()){
       tempmatch += match[j] ;
       j++ ;
      }
      match = tempmatch ;
      if(match.empty()) return "";

      }  
      return match ;
    }
};