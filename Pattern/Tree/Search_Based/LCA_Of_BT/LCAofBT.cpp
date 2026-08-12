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
TreeNode* ans = nullptr;
    int findans(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return 0;
        }
        int left = findans(root->left, p, q);
        int right = findans(root->right, p, q);

        int self = 0;

        if (root == p || root == q) {
            self = 1;
        }

        int sum = left + right + self;

        if (sum == 2 && ans == nullptr) {
            ans = root;
          
        }
          return sum;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        findans(root,p,q);
        return ans;
    }
};