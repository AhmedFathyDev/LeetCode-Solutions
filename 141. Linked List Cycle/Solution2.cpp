class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        map<ListNode *, bool> addresses;

        while (head != nullptr)
        {
            if (addresses[head])
                return true;

            addresses[head] = true;
            head = head->next;
        }

        return false;
    }
};
