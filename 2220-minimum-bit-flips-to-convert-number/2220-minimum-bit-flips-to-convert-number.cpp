class Solution {
public:
    int minBitFlips(int start, int goal) {
     int nums = start ^ goal ;
     int count = 0;
     while(nums){
        nums &= (nums-1);
        count++ ;
     }
     return count ;   
    }
};