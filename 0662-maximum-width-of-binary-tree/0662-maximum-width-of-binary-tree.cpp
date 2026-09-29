/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// have to repeat it yrr i am swelling ...
     int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int level_size = q.size();
            unsigned long long first_index = q.front().second;
            unsigned long long current_first = 0, current_last = 0;
            
            for (int i = 0; i < level_size; ++i) {
                auto [node, index] = q.front();
                q.pop();
                
                unsigned long long normalized_index = index - first_index;
                
                if (i == 0) current_first = normalized_index;
                if (i == level_size - 1) current_last = normalized_index;
                
                if (node->left) {
                    q.push({node->left, 2 * normalized_index});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalized_index + 1});
                }
            }
            
            max_width = max(max_width, current_last - current_first + 1);
        }
        
        return max_width;
    }
};