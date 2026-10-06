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
public://iam here for morris traversal amnd no one is gonna stop me not even my very own soul my thought my so called inner self
// i did it i am really very happy yrrr inner happienesss ....
    vector<int> inorderTraversal(TreeNode* root) {
     
       TreeNode* curr = root ;
       vector<int> result ;
       while(curr!= NULL ){
        if(curr->left == nullptr){
            result.push_back(curr->val);
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
       return result ;
    }
};