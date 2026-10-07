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
public: // just needed teh algo or before and rest is dome by bstiterator .. can revise if i want but i want this consept to stuck in my head ..
stack<TreeNode*> stn , stb;
void pushalln(TreeNode* root ){
    while(root!=NULL){
        stn.push(root);
        root= root->left;
    }
 }
 void pushallb(TreeNode* root ){
    while(root!=NULL){
        stb.push(root);
        root= root->right;
    }
 }
 int before() {
     TreeNode* tempnode = stb.top();
     stb.pop();
     pushallb(tempnode->left);  
     return tempnode->val ; 
    }
 int next() {
     TreeNode* tempnode = stn.top();
     stn.pop();
     pushalln(tempnode->right);  
     return tempnode->val ; 
    }
    bool findTarget(TreeNode* root, int k) {
        pushalln(root);
        pushallb(root);
         int i = next();
            int j = before();
        while(i<j){
          
            if(i+j > k){
             j = before();
            }else if(i+j<k){
                i= next();
            }else return true ;
        }
        return false ;

    }
};