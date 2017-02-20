//序列化二叉树的方法，先序遍历所有的节点，然后序列化成一个字符串。如果遇到空则序列化为”X"
//在解码的时候，采用递归解码的方式，输入采用queue的方式，会方便很多。
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    static void encode(StringBuffer ret, TreeNode node)
    {
        if(null == node)
        {
            ret.append("X,");
        }
        else
        {
            ret.append(node.val);
            ret.append(",");
            encode(ret, node.left);
            encode(ret, node.right);
        }

    }

    static TreeNode decode(Queue<String> que)
    {
        String s = que.poll();
        if(s.equals("X"))
            return null;
        TreeNode node = new TreeNode(Integer.parseInt(s));
        node.left = decode(que);
        node.right = decode(que);
        return node;
    }
    // Encodes a tree to a single string.
    public String serialize(TreeNode root)
    {
        StringBuffer sb = new StringBuffer();
        encode(sb, root);
        System.out.println(sb.toString());
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data)
    {
        String[] datas = data.split(",");
        Queue<String> que = new LinkedList<String>();
        for(int i = 0; i < datas.length; i++)
        {
            que.offer(datas[i]);
        }
        return decode(que);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));