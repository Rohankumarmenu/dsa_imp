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
int tgt;
bool ans;
void recurse(TreeNode* root,int sum){
   if(root==NULL){
    return;
   }
   sum=sum+root->val;
   if(root->left==NULL && root->right==NULL){
       if(tgt==sum){
        ans=true;
        return; 
       }
   }
   recurse(root->left,sum);
   recurse(root->right,sum);


}

    bool hasPathSum(TreeNode* root, int targetSum) {
        tgt=targetSum;
        ans=false;
        recurse(root,0);

        return ans;
    }
};