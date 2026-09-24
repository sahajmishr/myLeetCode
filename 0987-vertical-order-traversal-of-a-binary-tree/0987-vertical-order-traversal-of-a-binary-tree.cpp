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
// hey bhagwan kaise kar liya maine ye .. mujhe khud nahi pata,,,, mai firse kal karunga re baba .. 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode* , pair<int , int >>> todo ;
        map<int , map<int , multiset<int>>> node ;
        if(root) todo.push({root ,{0,0}});
        while(!todo.empty()){
            auto p  = todo.front();
            todo.pop();
            TreeNode* nodes = p.first;
            int x = p.second.first , y = p.second.second ;
            node[x][y].insert(nodes->val);
            if(nodes->left) todo.push({nodes->left ,{x-1 , y+1}});
            if(nodes->right) todo.push({nodes->right , {x+1 , y+1}});

        }
        vector<vector<int>> ans ;
        for(auto p : node){
            vector<int> ver ;
            for(auto q : p.second){
                ver.insert(ver.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(ver);
        }
        return ans ; 
    }
};