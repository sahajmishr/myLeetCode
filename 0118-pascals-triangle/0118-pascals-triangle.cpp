class Solution {
public:
    vector<int> nth(int n){
        vector<int> nt ;
        int ans = 1 ;
        nt.emplace_back(1);
     for(int i = 1 ; i<n ; i++){
        ans = ans*(n-i);
        ans =ans/i ;
        nt.emplace_back(ans);
        }
        return nt ;
     }
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> pascl ;
     /// and now i have to face it unless i can never be able to get out of this .....
     // eagle increases its hieght and raven suffers .. eagle does not look for shelter or hide him ...
     // consistency +smart work + reason = maja hehhehehhe 
     int  n= numRows;
     vector<int> ansa ;
   
     
     for(int i = n ; i>=1 ; i--){
         ansa = nth(i);
         pascl.emplace_back(ansa);
     }
     reverse(pascl.begin() , pascl.end());
        
     return pascl ;
        
    }
};