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
public: // have to return back with morris traversal .. i will come back tommorw mate
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                count++;
                if (count == k) {
                    result = curr->val;
                }
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    count++;
                    if (count == k) {
                        result = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};