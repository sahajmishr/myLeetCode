class Solution {
public:
    void reverseString(vector<char>& s) {

        // i knew its gonna be easy but unfortunately i have nothing to say ....
         int n = s.size();
        int left = 0 , right = n-1 ;
        char temp ;
       
        while(left<=right){
           temp = s[left];
           s[left] = s[right];
           s[right] = temp ;
           left++;
           right--; 
        }
        
       
    }
};