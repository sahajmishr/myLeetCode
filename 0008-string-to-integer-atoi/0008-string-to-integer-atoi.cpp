class Solution {
public:
    int myAtoi(string s) {
        // i was made for lovin you babyyyy ... i was made for lovin you ...
        int temp = -1; 
        
        long long val = 0;  
        int frst = 1;       
        for(int i = 0; i < s.size(); i++) {
            
             
            if((s[i] == ' ' || s[i] == '-' || s[i] == '+') && temp == -1) {
                if(s[i] == '-') frst = -1;
                if(s[i] == '+' || s[i] == '-') {
                    temp = 0;  
                }
                continue;
            }

          
            if(s[i] >= '0' && s[i] <= '9') {
                temp = 1; 
                val = val * 10 + (s[i] - '0'); 

                 
                if(val * frst > INT_MAX) return INT_MAX;
                if(val * frst < INT_MIN) return INT_MIN;
            } 
            
            else {
                break; 
            }
        } 

        val *= frst; 
        if(val > INT_MAX) return INT_MAX;
        if(val < INT_MIN) return INT_MIN;
        return val;
    }
};
