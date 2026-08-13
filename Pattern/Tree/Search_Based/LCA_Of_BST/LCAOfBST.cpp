/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) {
            return;
        }

        if (root == p || root == q) {
            ans = root;
            return;
        } else if (root->val < p->val) {
            findLCA(root->right, p, q);
        } else if (root->val > q->val) {
            findLCA(root->left, p, q);
        } else {
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (p->val < q->val) {
            findLCA(root, p, q);
        } else {
            findLCA(root, q, p);
        }
        return ans;
    }
};