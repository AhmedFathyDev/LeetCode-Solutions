class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;

        int lists_size = lists.size();

        while (lists_size)
        {
            ListNode *minNode = new ListNode(INT_MAX);
            ListNode *oldMinNode = minNode;
            int minNodeIndex = -1;

            for (int i = 0; i < lists_size; ++i)
                if (!lists[i])
                {
                    lists.erase(lists.begin() + i);
                    --lists_size;
                    --i;
                }
                else if (lists[i]->val < minNode->val)
                {
                    minNode = lists[i];
                    minNodeIndex = i;
                }

            if (oldMinNode == minNode)
                break;

            lists[minNodeIndex] = minNode->next;
            minNode->next = NULL;

            if (tail)
            {
                tail->next = minNode;
                tail = tail->next;
            }
            else
            {
                head = minNode;
                tail = minNode;
            }
        }

        return head;
    }
};
