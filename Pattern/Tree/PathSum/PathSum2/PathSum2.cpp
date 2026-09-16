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
    int tgt;
    // bool ans;
    vector<vector<int>> ans;
    vector<int> store;
    void recurse(TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        store.push_back(root->val);
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (tgt == sum) {
                ans.push_back(store);
            }
            store.pop_back();
            return;
        }
        recurse(root->left, sum);

        recurse(root->right, sum);
        store.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        tgt = targetSum;
        // ans=false;
        recurse(root, 0);

        return ans;
    }
};