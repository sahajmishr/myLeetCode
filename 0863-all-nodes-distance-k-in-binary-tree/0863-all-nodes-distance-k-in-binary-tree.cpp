/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { unordered_map<TreeNode*, TreeNode*> parentMap;

    void findParents(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        findParents(node->left, node);
        findParents(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root, nullptr);
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        
        int currentDistance = 0;
        
        while (!q.empty()) {
            if (currentDistance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap[curr] && visited.find(parentMap[curr]) == visited.end()) {
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            currentDistance++;
        }
        
        return {};
    }
};