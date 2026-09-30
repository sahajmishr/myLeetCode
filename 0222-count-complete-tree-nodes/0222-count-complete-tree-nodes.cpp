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
public:// i think that was easy mate isnt it ... btw i entered the winter arc with a sheer will dedication and decipline .... i will and only i will make it i am gonna fucking make it i am i am iam i am i am i am .. i will do what i think no more suggestion from my mind ... i will enslave my mind .
int findleft(TreeNode* root ){
    int hght = 0 ;
    while(root){
        hght ++ ;
        root = root-> left ;
    }
    return hght ;
}
int findright(TreeNode* root ){
    int hght = 0 ;
    while(root){
        hght++ ;
        root = root->right ;
    }
    return hght ;
}
    int countNodes(TreeNode* root) {
        if(!root) return 0 ;
        int lh = findleft(root);
        int rh = findright(root);
        if(lh == rh) return (1<<lh)-1 ;
        return (1+ countNodes(root->left)+ countNodes(root->right));
    }
};