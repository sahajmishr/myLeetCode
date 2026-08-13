class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min, profit = 0  , n = prices.size();
        min = prices[0];
        for(int i = 1 ; i < n ; i++) {
            if(prices[i]< min){
                min = prices[i];
            }
            if(profit<prices[i]-min){
                profit = prices[i] - min ;
            }
        }
        return profit ;
    }

        
};