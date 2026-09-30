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
public:// haaahhhahahzhhhhhhhhh.. nice game my mind but i already got you ..
TreeNode* previous = nullptr ;
void reverseorder(TreeNode* root ){
    if(!root) return ;
    reverseorder(root->right);
    reverseorder(root->left);
    root->right= previous ;
    root-> left = nullptr ;
    previous = root ;

}
    void flatten(TreeNode* root) {
        reverseorder(root); 
    }
};