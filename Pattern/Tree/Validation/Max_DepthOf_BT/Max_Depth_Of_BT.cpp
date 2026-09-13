
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
    int maxDepth(TreeNode* root) {
         TreeNode* k;
        int cnt = 0;
       queue<TreeNode*> q;
        if (root == NULL) {
            return 0;
        }
      
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n>0) {

                TreeNode* k = q.front();
                q.pop();
                // if (k->left == NULL && k->right == NULL) {
                //     return cnt;
                // }
                if (k->left != NULL) {
                    q.push(k->left);
                }
                if (k->right != NULL) {
                    q.push(k->right);
                }
                n--;
            }
            cnt++;
        }
        return cnt;
    }
};


//Recursive approach DFS

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
 