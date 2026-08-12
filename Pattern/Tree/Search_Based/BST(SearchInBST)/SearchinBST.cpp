
//Iteration based

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        while(root!=NULL && root->val!=val){
            if(val<root->val){
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return root;
    }
};


//Recursion based


class Solution {
public:
   
    TreeNode* searchBST(TreeNode* root, int val)
    {
         if(root==NULL)
         {
             return NULL;
         }
        if(root->val==val)  
        {
            return root;
        }
        if(val<root->val)
        {
            return searchBST(root->left, val);
        }
        else
        {
          return searchBST(root->right, val);                  
        }
       
    }
};