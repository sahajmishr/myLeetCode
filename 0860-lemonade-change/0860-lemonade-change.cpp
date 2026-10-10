class Solution {
public:// again i said its nothing greedy into it ....ughh my english sucks at the moment .
    bool lemonadeChange(vector<int>& bills) {
      map<int ,int> mp ;
      for(int i = 0 ; i< bills.size() ; i++){
        if(bills[i]== 5){
            mp[5]++;

        }else if(bills[i]==10&& mp[5]>0){
            mp[5]--;
            mp[10]++;
            
        }else if (bills[i]==20 ){
          if(mp[5]>0 && mp[10]>0){
            mp[5]--;
            mp[10]--;
          }else if (mp[5]>2){
            mp[5] -= 3 ;
          }else return false ;

        }else return false ;
      }  
      return true ;
    }
};