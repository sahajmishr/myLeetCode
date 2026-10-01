/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:// have to return here as well .. 

    // Encodes a tree to a single string.
       string serialize(TreeNode* root) {
        if (!root) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (!curr) {
                s += "null,";
            } else {
                s += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data.empty()) return nullptr;

        vector<string> nodes;
        string current_item = "";
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                nodes.push_back(current_item);
                current_item = "";
            } else {
                current_item += data[i];
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int index = 1;
        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            if (nodes[index] != "null") {
                TreeNode* leftChild = new TreeNode(stoi(nodes[index]));
                parent->left = leftChild;
                q.push(leftChild);
            }
            index++;

            if (nodes[index] != "null") {
                TreeNode* rightChild = new TreeNode(stoi(nodes[index]));
                parent->right = rightChild;
                q.push(rightChild);
            }
            index++;
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));