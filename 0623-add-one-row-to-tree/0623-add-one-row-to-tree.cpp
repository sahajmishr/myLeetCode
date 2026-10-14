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
public:// for streak of 14 october ..copied
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        
        while (!q.empty()) {
            int size = q.size();
            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    TreeNode* leftChild = curr->left;
                    TreeNode* rightChild = curr->right;
                    
                    curr->left = new TreeNode(val);
                    curr->right = new TreeNode(val);
                    
                    curr->left->left = leftChild;
                    curr->right->right = rightChild;
                }
                break;
            }
            
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            currentDepth++;
        }
        
        return root;
    }
};
