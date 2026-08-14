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
    int maxi = 0;
    unordered_map<int, int> umap;
    void findDepth(TreeNode* root, int d) {

        if (root == NULL) {
            return;
        }
        maxi = max(maxi, d);
        umap[root->val] = d;
        findDepth(root->left, d + 1);
        findDepth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || umap[root->val] == maxi) {
            return root;
        }

        TreeNode* l = LCA(root->left);

        TreeNode* r = LCA(root->right);

        if (l && r) {
            return root;
        }

        if (l != NULL) {
            return l;
        } else {
            return r;
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        findDepth(root, 0);

            return LCA(root);
    }
};


//