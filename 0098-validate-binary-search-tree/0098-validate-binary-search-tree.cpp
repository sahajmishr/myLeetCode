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
public: // rang de na .. apne he rang me morris bhai you are a genius yrr ....
    bool isValidBST(TreeNode* root) {
        if(!root) return true ;
         TreeNode* curr = root ;
         TreeNode* prev = nullptr;
        while(curr!= NULL ){
        if(curr->left == nullptr){
            
             TreeNode* rightt = curr->right;
                 if (prev != nullptr && prev->val >= curr->val) return false;
           prev = curr;
       
        curr = curr->right;

        }else{
            TreeNode* temp = curr->left ;
            TreeNode* leftchild = curr->left ;
            while(leftchild->right != nullptr ){
                leftchild = leftchild->right;

            }
            leftchild->right = curr ;
            curr->left = nullptr;
            curr = temp ;

        }
       } 
       return true ;
    }
};