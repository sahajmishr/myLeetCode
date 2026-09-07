class Solution {
     int histogram(vector<int>& heights) {
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
public:
// ahhhhhhh abomination ;;
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) return 0;
       int  n = matrix.size();
       int m = matrix[0].size();
       int maxarea = 0 ;
        vector<int> heights(m, 0);
          
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                // If current cell is '1', add to previous height. If '0', reset to 0.
                if(matrix[i][j] == '1'){ 
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Pass the generated row's heights into your histogram function
            maxarea = max(maxarea, histogram(heights));
        } 
        return maxarea;
    }
};