class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int list_node_length = 0;
        ListNode *temp_head = head;

        while (temp_head)
        {
            ++list_node_length;
            temp_head = temp_head->next;
        }

        if (n == list_node_length)
            return head->next;

        temp_head = head;

        for (int i = 0; temp_head->next && i < list_node_length - n - 1; ++i)
            temp_head = temp_head->next;

        temp_head->next = temp_head->next->next;

        return head;
    }
};
