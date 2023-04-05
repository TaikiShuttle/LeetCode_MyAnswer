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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        //push back
        q.push(root);
        int size = q.size();
        while (!q.empty()) {
            vector<int> thislevel;
            for (int i = 0; i < size; i++) {
                TreeNode * node = q.front();
                thislevel.push_back(node->val);
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            result.push_back(thislevel);
            size = q.size();
        }

        return result;
    }
};
