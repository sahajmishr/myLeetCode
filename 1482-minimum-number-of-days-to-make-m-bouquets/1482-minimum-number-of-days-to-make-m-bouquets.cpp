bool possible(vector<int>& bloomDay , int day , int m , int k  ){
    int count = 0 , nB = 0 ;
    long long n = bloomDay.size();
    for(int i = 0 ; i<n ; i++){
        if(bloomDay[i] <= day){
            count++;
            if(count == k){
                nB++;
                 count = 0;
            }
        }else {
           
            count = 0;
        }
        
    }
    
        return nB>=m;
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       long long n =bloomDay.size();
        if((long long) m*k > n) return -1 ;
        int mn = *min_element(bloomDay.begin() , bloomDay.end());
        int mx = *max_element(bloomDay.begin() , bloomDay.end()) ;
        int ans = mx ;
        
        
        while(mn<= mx){
           int mid = (mn+mx)/2;
           bool val = possible(bloomDay, mid , m , k  );
           if(val==true){
            ans = min(mid , ans);
            mx = mid-1;
           } else {
            mn = mid+1 ;
           }
        }
        return ans ;
        
        
    }
};