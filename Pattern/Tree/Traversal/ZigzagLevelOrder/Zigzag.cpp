
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
         bool LtoR=true;
        if (root == NULL) {
            return ans;
        }

        
        queue<TreeNode*> q;
        q.push(root);
        while (!q .empty()) {
            int n = q.size();
            vector<int> store(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int ind=LtoR ? i : (n-1-i);
                store[ind] = node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                // store.push_back(node->val);
                //   store.push_back();
            }
            ans.push_back(store);
            LtoR=!LtoR;
        }
        return ans;
    }
};