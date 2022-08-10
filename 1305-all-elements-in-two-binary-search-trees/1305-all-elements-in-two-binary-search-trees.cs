/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<int> GetAllElements(TreeNode root1, TreeNode root2) {
        var list1 = new List<int>();
        var list2 = new List<int>();

        void InOrder(TreeNode? root, List<int> list)
        {
            if (root is null)
            {
                return;
            }

            InOrder(root.left, list);

            list.Add(root.val);

            InOrder(root.right, list);
        }

        InOrder(root1, list1);
        InOrder(root2, list2);

        list1.AddRange(list2);
        list1.Sort();

        return list1;
    }
}