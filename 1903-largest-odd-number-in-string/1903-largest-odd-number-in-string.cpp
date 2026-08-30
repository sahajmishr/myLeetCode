class Solution {
public:
    string largestOddNumber(string num) {
      
      int n  = num.size();
       int x = n - 1;
       
    
       while(x >= 0 && num[x] % 2 == 0){
           x--;
       }
       
       
       if (x < 0) return "";
       
       
       return num.substr(0, x + 1);
    }
};