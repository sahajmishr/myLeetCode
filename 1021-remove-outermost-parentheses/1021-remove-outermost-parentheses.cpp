class Solution {
public:
    string removeOuterParentheses(string s) {
      string result = "";  
        // no words ...
        int level = 0;       
        int n = s.size();
       
        for (int i = 0 ; i < n ; i++) {
            
            if (s[i] == '(') {
               
                if (level > 0) result += s[i];
               
                level++;  
            } 
         
            else if (s[i]== ')') {
               
                level--;  
                
                if (level > 0) result += s[i];
            }
        }

        
        return result;  
    }
};