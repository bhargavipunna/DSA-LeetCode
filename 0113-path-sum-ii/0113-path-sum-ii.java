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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>>ans = new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        help(ans,res,root,targetSum);
        return ans;
    }
    void help(List<List<Integer>> ans, List<Integer> res, TreeNode root, int targetSum) {
        if (root == null) {
            return;
        }
        res.add(root.val);

        if (root.left == null && root.right == null && targetSum == root.val) {
            ans.add(new ArrayList<>(res));
        } else {
            help(ans, res, root.left, targetSum - root.val);
            help(ans, res, root.right, targetSum - root.val);
        }
        res.remove(res.size() - 1);
    }
}