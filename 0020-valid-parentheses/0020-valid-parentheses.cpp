class Solution {
public:
stack<char> st ;
    bool isValid(string s) {
        if(s.size()==1) return false ;
       for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        st.push(s[i]);
        else{
            if (st.empty()) return false;
            char tp = st.top();
           if(tp=='('&& s[i]!=')') return false ;
           if(tp=='{'&& s[i]!='}') return false ;
           if(tp=='['&& s[i]!=']') return false ;
           st.pop();
        }
       }
       // i think i am being shana .. but this time i am ready to fall and rise again .
      return st.empty();
    }
};