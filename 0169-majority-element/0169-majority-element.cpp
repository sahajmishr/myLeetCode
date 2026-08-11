class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() , maxVal = 0  , majElem ;
        map<int , int > mp;
        for(int i = 0 ; i <n ;i++ ){
            if(mp.contains(nums[i])){
                mp[nums[i]]++;

            }else{
                mp.emplace(nums[i] , 1 );
            }
        }
        for(int i = 0 ; i<n ;i++){
            if(mp[nums[i]]>maxVal){
                maxVal = mp[nums[i]];
                majElem = nums[i];
                
            }
        }
        return majElem ; 
        
    }
};