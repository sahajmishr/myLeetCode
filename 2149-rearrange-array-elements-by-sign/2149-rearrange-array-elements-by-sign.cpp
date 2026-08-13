class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // pehle positive ko pehli position deni hai fir pehli negative fir dusra positive fir dusra positive fir dusra negative and so on ....
        int pos=0 , neg=1 , n = nums.size();
        vector<int> newarr(n);
         
        for(int i = 0 ; i<n ;i++){
            if(nums[i]>0){
                newarr[pos]=nums[i];
                pos+=2 ;
                
            }
            if(nums[i]<0){
                newarr[neg] = nums[i];
                neg+=2 ;
            }
        }


        return newarr ;
        
    }
};