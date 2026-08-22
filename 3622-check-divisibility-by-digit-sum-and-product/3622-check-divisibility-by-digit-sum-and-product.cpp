


class Solution {
public:
int sum(int n) {
    int tsum = 0;
    while (n > 0) {
        tsum += n % 10; 
        n /= 10;       
    }
    return tsum;
}
// i am crying....
int prod(int n) {
    int tprod = 1 ;
    while(n>0){
        tprod *= n%10;
        n /=10 ;
    }
    return tprod ;
}
    bool checkDivisibility(int n) {
        int sm = sum(n); 
        int prd = prod(n);
        sm +=prd ;
        if(n%sm ==0) return true ;
        else return false;
    }
};