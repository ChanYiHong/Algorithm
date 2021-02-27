package DFSBFS;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class TreeBFS {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println(solve(root));
    }

    private static List<List<Integer>> solve(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();

        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        list.add(root.val);
        ret.add(list);
        queue.offer(root);

        System.out.println(queue.size());

        while(!queue.isEmpty()) {
            List<Integer> nodeList = new ArrayList<>();
            TreeNode node = queue.poll();
            if(node.left != null) {
                nodeList.add(node.left.val);
                queue.offer(node.left);
            }
            if(node.right != null) {
                nodeList.add(node.right.val);
                queue.offer(node.right);
            }
            if(nodeList.size() != 0) ret.add(nodeList);
        }

        return ret;
    }
}
