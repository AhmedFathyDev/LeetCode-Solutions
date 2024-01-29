class Solution
{
public:
    void reorderList(ListNode *head)
    {
        int list_node_length = 0;

        stack<ListNode *> reversed_head;

        ListNode *temp_head = head;

        while (temp_head != nullptr)
        {
            ++list_node_length;

            reversed_head.push(temp_head);

            temp_head = temp_head->next;
        }

        temp_head = head;

        for (int i = 0; i < list_node_length / 2; ++i)
        {
            reversed_head.top()->next = temp_head->next;
            temp_head->next = reversed_head.top();

            reversed_head.pop();
            temp_head = temp_head->next->next;
        }

        temp_head->next = nullptr;
    }
};
