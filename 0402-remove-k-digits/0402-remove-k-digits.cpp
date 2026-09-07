class Solution {
public:
      string removeKdigits(string nums, int k) {
      // dont know why i am struggling withwriting code while logic is easy .. like iam getting each logic points very easily but when it comes to writing sybtax its struggling .. maybe i need to revise syntaxes ....  
        stack <char> st;  
        for(int i=0; i < nums.size(); i++) {
            
            
            char digit = nums[i];
            
           
            while(!st.empty() && k > 0
                  && st.top() > digit) {

                st.pop(); 
                k--;
            }
            
            
            st.push(digit);
        }
        
      
        while(!st.empty() && k > 0) {
            
            st.pop();
            k--; 
        }
        
        
        if(st.empty()) return "0";
        
      
        string res = "";
        
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        
        while(res.size() > 0 && 
              res.back() == '0') {

            res.pop_back();
        }
        
        
        reverse(res.begin(), res.end());
        
     
        if(res.empty()) return "0";
        
       
        return res;
    }
};