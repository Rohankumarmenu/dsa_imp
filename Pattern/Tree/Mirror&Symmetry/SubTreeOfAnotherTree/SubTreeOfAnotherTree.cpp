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

string ans;
   string preorderhelper(TreeNode* node){
      if( node==NULL){
         return "#,";
        }
        return ","+to_string(node->val) + ","
        +preorderhelper(node->left)
        +preorderhelper(node->right);

 }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    
        string ans1 = preorderhelper(root);
        string ans2 = preorderhelper(subRoot);

        return ans1.find(ans2) != string::npos;


    }
};