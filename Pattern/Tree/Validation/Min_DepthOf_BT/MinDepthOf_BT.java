/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        

        int cnt = 1;
    Queue<TreeNode>q =new LinkedList<>();
        if (root == null) {
            return 0;
        }
      
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            while (n>0) {

                TreeNode k = q.peek();
                q.remove();
                if (k.left == null && k.right == null) {
                    return cnt;
                }
                if (k.left != null) {
                    q.add(k.left);
                }
                if (k.right != null) {
                    q.add(k.right);
                }
                n--;
            }
            cnt++;
        }
        return cnt;
     

    }
}
