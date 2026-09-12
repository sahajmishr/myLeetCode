class Solution {
public:
    string reverseWords(string s) {
       int n = s.size();
       string ans = "";
       // haah either i did it or i did it nothing else ...
       reverse(s.begin() , s.end());    
       for(int i = 0 ; i<n ; i++ ){
        while(i<n&& s[i]==' ') i++ ;
        if(i== n ) break ;
        string word = "";
        while(i<n&& s[i]!= ' '){
            word+=s[i];
            i++ ;
        }
        reverse(word.begin(), word.end());
        if(ans.size()>0) ans+= ' '+word ;
        else ans+= word ;

       }
       return ans ;
    }
};