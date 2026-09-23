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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>> result ;
         int flag  = 1 ;
// you just want attention .. you dont want my heart ..

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
          if(flag == 0){
          reverse(currlevel.begin() , currlevel.end());
          flag = 1 ;
          } else flag = 0 ;
          result.push_back(currlevel);
         }
         return result ;
    }
};