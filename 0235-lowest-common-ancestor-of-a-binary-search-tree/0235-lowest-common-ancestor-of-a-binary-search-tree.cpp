/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:// just trying if it could work or not if worked that willl be greattt but these comments are genuinely mine just fo rrefrences i added .. 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (p->val > q->val) {
        TreeNode* temp = p;
        p = q;
        q = temp;
    }
       // either left or right 
     while(root!= nullptr){
          if(p->val < root->val && q->val > root-> val ) return root ;
       // both left 
       if(p->val < root-> val && q->val < root-> val ) root = root-> left ;
       // both right
       if(p->val > root->val && q->val > root-> val ) root =  root->right ;

       // one can be the one 
       if(root-> val == q->val){
        return q ;
       }
        if(root->val== p-> val ){
        return p ;
       }
       
     }

       return root ;
    }
};