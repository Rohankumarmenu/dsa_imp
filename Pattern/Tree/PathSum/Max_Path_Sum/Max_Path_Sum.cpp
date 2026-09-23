
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

int maxi;
int recurse(TreeNode* root){

    if(root==NULL){
        return 0;
    }


  int l=recurse(root->left);

  int r=recurse(root->right);

  int find_ans_below=l+r+root->val;

  int either_left_OR_right=max(l,r)+root->val;

  int neither_left_nor_right=root->val;

  maxi=max({maxi,find_ans_below,either_left_OR_right,neither_left_nor_right});

  return max(either_left_OR_right,neither_left_nor_right);
}
    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
       recurse(root); 
       return maxi;
    }
};