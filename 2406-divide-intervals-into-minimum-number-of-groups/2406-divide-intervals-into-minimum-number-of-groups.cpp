class Solution {
public:// will surely return mate to solve you ... soon soon 
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        
        for (const auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        
       
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int max_groups = 0;
        int active_groups = 0;
        int end_ptr = 0;
        
         
        for (int i = 0; i < starts.size(); i++) {
          
            if (starts[i] > ends[end_ptr]) {
                end_ptr++;
            } else {
                
                max_groups++; 
            }
        }
        
        return max_groups;
    }
};