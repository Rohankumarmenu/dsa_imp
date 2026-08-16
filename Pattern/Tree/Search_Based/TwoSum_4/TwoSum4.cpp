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
  void inOrder(TreeNode* root, vector<int> &in){
        if(!root) return;
        inOrder(root->left, in);
        in.push_back(root->val);
        inOrder(root->right, in);
    }
    bool findTarget(TreeNode* root, int k) {
          vector<int> ans;
        inOrder(root, ans);
        int i = 0, j = ans.size() - 1;
        //Two pointer approach
        while(i<j){
            if(ans[i] + ans[j] == k) return true;
            if(ans[i] + ans[j] > k) j--;
            else i++;
        }
        return false;
    }
};


class Solution {
public:
    set<int>s;
    bool findTarget(TreeNode* root, int k) {
       
        if(!root){
            return false;
        }
        if(s.find(k-root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k); //Recursion based



    }
};
