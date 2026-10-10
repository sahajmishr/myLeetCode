class Solution {
public:// nothing greedy into it btw ..
    int findContentChildren(vector<int>& g, vector<int>& s) {
     sort(s.begin() , s.end());
     sort(g.begin(), g.end());
     int count = 0 ;
     int i = 0 ,  j= 0 ; 
     while(i<s.size() && j< g.size()){
        if(g[j]<= s[i]){
            count ++;
            i++;
            j++;
        }else{
            i++;
        }
     }  
     return count ; 
    }
};