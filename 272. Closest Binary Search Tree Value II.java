/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//中序遍历，一定是递增序列
//然后用一个双端队列，K个数一定是相连的，找到区间即可。
//区间结束标志就是无法替换为止
public class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        LinkedList<Integer> res = new LinkedList<>();
        inOrderTraversal(root, target, k, res);
        return res;
    }
    
    private void inOrderTraversal(TreeNode root, double target, int k, LinkedList<Integer> res) {
        if (root == null) {
            return;
        }
        inOrderTraversal(root.left, target, k, res);
        if (res.size() < k) {
            res.add(root.val);
        } else if(res.size() == k) {
            if (Math.abs(res.getFirst() - target) > (Math.abs(root.val - target))) {
                res.removeFirst();
                res.addLast(root.val);
            } else {
                return;
            }
        }
        inOrderTraversal(root.right, target, k, res);
    }
}