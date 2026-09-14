class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     // last time time i copoied from striver and as i said i will come back and i am a kan of my word i came nback and now i am gonna keep my promise ...solved it on my own wit proper understanding ....

     int n = fruits.size();
     int r = 0 , l = 0 , maxlen = 0 ;
     map<int,int> mpp ;
     while(r<n){
       mpp[fruits[r]]++;
       if(mpp.size()>2){
        mpp[fruits[l]]--;
        if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
        l++ ;
       }
       if(mpp.size()<= 2){
       maxlen = max(maxlen , r-l+1);
       }
       r++;
     }
     return maxlen ;   
    }
};