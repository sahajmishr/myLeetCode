class Solution {
public:
stack<int> st ;
unordered_map<int , int > nge ;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // if no means no .. 
      int n = nums2.size();
      for(int i= n-1 ; i >= 0 ; i--){
        while(!st.empty() && st.top() <= nums2[i]){
        st.pop();
        }
        
          nge[nums2[i]] = st.empty() ? -1 : st.top();
      st.push(nums2[i]);

      }  
     
       vector<int> sol(nums1.size());
       for(int i = 0 ; i<nums1.size(); i++ ){
        sol[i] = nge[nums1[i]];
        }
    return sol ;
    }
   
};