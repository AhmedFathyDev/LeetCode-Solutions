/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        var curNode = new ListNode();
        var sumList = curNode;

        var carry = 0;

        while (l1 != null || l2 != null || carry > 0)
        {
            var val1 = l1 == null ? 0 : l1.val;
            var val2 = l2 == null ? 0 : l2.val;

            var val = val1 + val2 + carry;

            carry = val / 10;
            val = val % 10;

            curNode.next = new ListNode(val);
            curNode = curNode.next;

            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }

        return sumList.next ?? sumList;
    }
}