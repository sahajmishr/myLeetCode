class Solution {
public: // kindda copied but easy to understand .. and i could digest it ...
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Put all words into a hash set for O(1) lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // Base Case: If the destination word isn't in the list, it's impossible
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        // Step 2: Set up the BFS queue
        // We store pairs of {current_word, current_path_length}
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // The path starts with length 1 (the beginWord itself)
        
        // Step 3: Begin BFS
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            
            // If we reached the target word, return the step count immediately
            if (word == endWord) return steps;
            
            // Try changing each character of the word from 'a' to 'z'
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // Substitute character
                    
                    // If this new word exists in our valid pool
                    if (wordSet.find(word) != wordSet.end()) {
                        // Remove it from the set so we don't visit it again (prevents infinite loops)
                        wordSet.erase(word); 
                        // Push to queue with an incremented step count
                        q.push({word, steps + 1});
                    }
                }
                
                word[i] = originalChar; // Revert back for the next position loop
            }
        }
        
        // If the queue becomes empty and we never hit endWord, no path exists
        return 0;
    }
};