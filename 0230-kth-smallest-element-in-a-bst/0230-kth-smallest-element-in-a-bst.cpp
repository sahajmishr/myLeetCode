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
public:// yeah smashed with morris bhai ... heheehehhheehhehe
    int kthSmallest(TreeNode* root, int k) {
     TreeNode* curr = root ;
       int kt = 0;
       while(curr!= NULL ){
        if(curr->left == nullptr){
             kt++ ;
             if(kt == k ) return curr->val ;
            curr = curr->right ;
           

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
       return curr->val ;
    }
};