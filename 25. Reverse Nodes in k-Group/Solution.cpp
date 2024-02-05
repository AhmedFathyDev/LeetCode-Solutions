class Solution
{
private:
    ListNode *reverse_list(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *new_head = reverse_list(head->next);

        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }

    ListNode *k_node(ListNode *head, int k)
    {
        while (head && --k)
            head = head->next;

        return head;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *list_head = head;

        ListNode *prev_list_tail = NULL;

        while (list_head)
        {
            ListNode *list_tail = k_node(list_head, k);

            if (!list_tail)
            {
                if (prev_list_tail)
                    prev_list_tail->next = list_head;

                break;
            }

            ListNode *next_list_head = list_tail->next;
            list_tail->next = NULL;

            reverse_list(list_head);

            if (list_head == head)
                head = list_tail;
            else
                prev_list_tail->next = list_tail;

            prev_list_tail = list_head;
            list_head = next_list_head;
        }

        return head;
    }
};
