class StockSpanner {
public:
 int priceind = -1 ;
stack<pair<int,int >> st ;
    StockSpanner() {
        
    }
   // in dont know its just max , shamani , and striver .... 
    int next(int price) {
       priceind++; 
       while(!st.empty() && st.top().second <= price){
        st.pop();
       }
      int rt = st.empty()? (priceind+1) : priceind-(st.top().first) ;
       st.push({priceind , price});
       return rt ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */