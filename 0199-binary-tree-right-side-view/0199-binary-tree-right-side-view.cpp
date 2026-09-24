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
// lakk 28 kuddi da .. 47 weight kuddi da ... kaddi te hass bolve 
    vector<int> rightSideView(TreeNode* root) {
     vector<vector<int>> result ;
         vector<int> ans ;
         if(!root) return ans ;
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
         vector<int> temp ;
          for(int i = 0 ; i<result.size() ;i++ ) {
            temp = result[i];
            ans.push_back(temp[temp.size()-1]);
          }
          return ans ;
    }
};