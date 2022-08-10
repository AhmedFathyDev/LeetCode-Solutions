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
        void InOrder(TreeNode? root, ICollection<int> list)
        {
            if (root is null)
            {
                return;
            }

            InOrder(root.left, list);

            list.Add(root.val);

            InOrder(root.right, list);
        }
        
        var list1 = new List<int>();
        var list2 = new List<int>();
        var list = new List<int>();

        InOrder(root1, list1);
        InOrder(root2, list2);

        while (list1.Count > 0 && list2.Count > 0)
        {
            if (list1.First() < list2.First())
            {
                list.Add(list1.First());
                list1 = list1.Skip(1).ToList();
            }
            else
            {
                list.Add(list2.First());
                list2 = list2.Skip(1).ToList();
            }
        }

        while (list1.Count > 0)
        {
            list.Add(list1.First());
            list1 = list1.Skip(1).ToList();
        }
        
        while (list2.Count > 0)
        {
            list.Add(list2.First());
            list2 = list2.Skip(1).ToList();
        }

        return list;
    }
}