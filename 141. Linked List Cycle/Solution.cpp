class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast_node = head;
        ListNode *slow_node = head;

        while (fast_node && fast_node->next)
        {
            fast_node = fast_node->next->next;
            slow_node = slow_node->next;

            if (fast_node == slow_node)
                return true;
        }

        return false;
    }
};
