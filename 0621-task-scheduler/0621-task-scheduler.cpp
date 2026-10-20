class Solution {
public: // fuck you oversmartnessi hate oversmart people bloddy shitty .. nali ke kide .. aukaat se jyada bhaav milne pe aukaat he bhul jaate hai 
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        int time = 0;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i] - 'A']++;
        }
        priority_queue<int> freq;
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] > 0) {
                freq.push(mp[i]);
            }
        }
        while (!freq.empty()) {
            vector<int> temp;
            int cycle_count = 0;  
            
            for (int i = 1; i <= n + 1; i++) {
                if (!freq.empty()) {  
                    int tp = freq.top(); freq.pop();
                    tp--;
                    temp.push_back(tp);
                    cycle_count++; 
                }
            }
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] > 0) {
                    freq.push(temp[i]);
                }
            }
             
            if (freq.empty()) {
                time += cycle_count;
            } else {
                time += (n + 1);
            }
        }
        return time;
    }
};
