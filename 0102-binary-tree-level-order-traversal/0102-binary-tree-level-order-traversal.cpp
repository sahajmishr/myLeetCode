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
// i did say that i will come back mate and i am keeping my word ....
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result ;
         
         if(!root) return result ;
         queue<TreeNode* > q ;
         q.push(root);
         while(!q.empty()){
            int size = q.size();
          vector<int> currlevel ;
          for(int i = 0 ; i <size ; i++){
            TreeNode* node = q.front();
            q.pop();
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
             currlevel.push_back(node->val);
          }
          result.push_back(currlevel);
         }
         return result ;
    }
};