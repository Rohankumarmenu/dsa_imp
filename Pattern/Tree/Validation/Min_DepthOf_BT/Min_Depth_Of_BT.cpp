
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
//Iterative approach using BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        TreeNode* k;
        int cnt = 1;
       queue<TreeNode*> q;
        if (root == NULL) {
            return 0;
        }
      
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {

                TreeNode* k = q.front();
                q.pop();
                if (k->left == NULL && k->right == NULL) {
                    return cnt;
                }
                if (k->left != NULL) {
                    q.push(k->left);
                }
                if (k->right != NULL) {
                    q.push(k->right);
                }
            }
            cnt++;
        }
        return cnt;
    }
};


//Recursive approach