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
  
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;

    
        st.push({p, q});

   
        while (!st.empty()) {
            auto [nodeP, nodeQ] = st.top();
            st.pop();

            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }

         
            if (nodeP == nullptr || nodeQ == nullptr) {
                return false;
            }

           
            if (nodeP->val != nodeQ->val) {
                return false;
            }

            
            st.push({
                nodeP->right,
                nodeQ->right
            });

            st.push({
                nodeP->left,
                nodeQ->left
            });
        }

        return true;
    }
};