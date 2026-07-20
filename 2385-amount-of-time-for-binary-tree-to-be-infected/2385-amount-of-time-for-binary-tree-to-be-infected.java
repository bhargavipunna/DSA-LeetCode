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
    private void buildParentMap(TreeNode node, TreeNode parent, Map<TreeNode, TreeNode> parents) {
        if (node == null) return;
        parents.put(node, parent);
        buildParentMap(node.left, node, parents);
        buildParentMap(node.right, node, parents);
    }

    private TreeNode findStartNode(TreeNode node, int start) {
        if (node == null) return null;
        if (node.val == start) return node;
        TreeNode left = findStartNode(node.left, start);
        if (left != null) return left;
        return findStartNode(node.right, start);
    }

    public int amountOfTime(TreeNode root, int start) {
        Map<TreeNode, TreeNode> parents = new HashMap<>();
        buildParentMap(root, null, parents);

        TreeNode startNode = findStartNode(root, start);

        Map<TreeNode, Boolean> visited = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(startNode);
        visited.put(startNode, true);

        int minutes = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean spread = false;

            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();

                if (curr.left != null && !visited.containsKey(curr.left)) {
                    visited.put(curr.left, true);
                    queue.offer(curr.left);
                    spread = true;
                }
                if (curr.right != null && !visited.containsKey(curr.right)) {
                    visited.put(curr.right, true);
                    queue.offer(curr.right);
                    spread = true;
                }
                TreeNode parent = parents.get(curr);
                if (parent != null && !visited.containsKey(parent)) {
                    visited.put(parent, true);
                    queue.offer(parent);
                    spread = true;
                }
            }

            if (spread) {
                minutes++;
            }
        }

        return minutes;
    }
}