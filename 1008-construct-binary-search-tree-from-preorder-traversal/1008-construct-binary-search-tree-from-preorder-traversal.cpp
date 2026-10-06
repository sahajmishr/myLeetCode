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
public:// will have to do it again iam not satisfied yet ... 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       
        TreeNode* root = new TreeNode(preorder[0]);
       
        for(int i = 1 ; i < preorder.size(); i++){
            TreeNode* temp = root;
            TreeNode* parent = nullptr;  
            while(temp != nullptr){
                parent = temp;
                if(preorder[i] > temp->val) temp = temp->right;
                else temp = temp->left;
            }
            
           
            if(preorder[i] > parent->val){
                parent->right = new TreeNode(preorder[i]);
            } else {
                parent->left = new TreeNode(preorder[i]);
            }
        } 
        return root;
    }
};
