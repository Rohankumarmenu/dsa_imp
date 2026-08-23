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
 int ans=INT_MIN;
int diameter(TreeNode* root){
    if(!root){
        return 0;
    }
        int leftHeight=diameter(root->left);
        int rightHeight=diameter(root->right);

        // return max(leftHeight,rightHeight)+1;

      ans=max(ans,leftHeight+rightHeight);

      return max(leftHeight,rightHeight)+1;

}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        diameter(root);
      
      return ans;
    }
};