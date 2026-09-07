class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st ; 
       // kata tara  raat tohar  daru  namkeen par .... nice song though....
       int element , nse , pse  , maxarea=0 , currarea ;
       for(int i = 0 ; i< heights.size() ; i++){
       while(!st.empty()&& heights[st.top()] > heights[i]){
        element = st.top() ;
        st.pop();
        nse = i;
         pse = st.empty() ? -1 : st.top();
        currarea = (nse-pse-1)*heights[element];
        maxarea = max(maxarea ,currarea );
        
       }
       st.push(i);
    }
       
       while(!st.empty())
       {
        element = st.top();
        st.pop();
        nse = heights.size() ;
        pse = st.empty()? -1 : st.top();
        currarea = (nse-pse-1)*heights[element];
        maxarea = max(maxarea ,currarea );
       
       }

       return maxarea ;
        
    }
};