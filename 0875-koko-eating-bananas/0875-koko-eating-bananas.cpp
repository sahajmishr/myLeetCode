long long hr(vector<int>& piles, int l ){
    int pl = piles.size();
    long long th = 0 ;
    for(int i = 0 ; i<pl ;i++){
        th += ceil((double)piles[i]/l);
    }
    return th ;
}
// just the double ... are you comedy me ...
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size() ; 
        int low = 1 , high = *max_element(piles.begin(), piles.end()) , mid = 0 , ans=0  ;
        while(low<= high){
            mid = (low+high)/2 ;
            if(hr( piles , mid)<=h){
                ans = mid ;
                high = mid-1 ;
            }else {
                low = mid+1 ;
            }
        }
        return ans ;
        
    }
};