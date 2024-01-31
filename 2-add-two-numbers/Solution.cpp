class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *current_node = new ListNode();
        ListNode *new_l = current_node;
        int carry = 0;

        while (l1 || l2 || carry > 0)
        {
            int l1_d = l1 ? l1->val : 0;
            int l2_d = l2 ? l2->val : 0;

            current_node->next = new ListNode((l1_d + l2_d + carry) % 10);
            carry = (l1_d + l2_d + carry) / 10;
            current_node = current_node->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return new_l->next;
    }
};
