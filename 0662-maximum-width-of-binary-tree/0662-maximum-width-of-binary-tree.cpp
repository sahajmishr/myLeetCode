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
    int widthOfBinaryTree(TreeNode* root) {
      // came back for repeating mate ..   
      queue <pair<TreeNode* , int >> q ;
      int ans ;
      if(!root) return 0 ;
      int mmin ;
      q.push({root ,0 });
      while(!q.empty()){
       int s = q.size();
       int first , last ;
       mmin = q.front().second ;
       for(int i = 0 ; i< s ; i++){
        unsigned long long  curr_id = q.front().second - mmin ;
        TreeNode* node = q.front().first ;
        q.pop();
        if(i==0) first = curr_id ;
        if(i== s-1 ) last = curr_id;

        if(node-> left ) q.push({node->left , curr_id*2+1});
        if(node->right) q.push({node->right , curr_id*2+2});

       

       }
        ans = max(ans , last-first+1);

      }
      return ans ;
    }
};