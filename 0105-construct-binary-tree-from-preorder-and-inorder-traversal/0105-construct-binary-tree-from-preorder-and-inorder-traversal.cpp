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
 */// naina lage to jage bin adori ya tage .. bandhte hai do khwab se ..
class Solution {
    TreeNode* build(vector<int>& preorder, vector<int>& inorder , int instart , int inend , int prestart , int preend , unordered_map<int , int>& inmap ){
        if(instart>inend || prestart > preend) return nullptr ;

    TreeNode* root = new TreeNode(preorder[prestart]);
    int inroot = inmap[root->val];
    int leftpart = inroot - instart ;
  root->left = build(preorder , inorder , instart , inroot-1 , prestart+1 , prestart+leftpart , inmap);
  root->right = build(preorder ,inorder , inroot+1 , inend , prestart+leftpart+1 , preend , inmap);
   return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return build(preorder , inorder , 0 , inorder.size()-1 , 0 , preorder.size() , inmap);
    }
};