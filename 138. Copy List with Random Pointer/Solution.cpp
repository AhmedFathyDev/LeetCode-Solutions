class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> new_nodes;
        Node *temp_head = head;

        while (temp_head)
        {
            new_nodes[temp_head] = new Node(temp_head->val);
            temp_head = temp_head->next;
        }

        temp_head = head;

        while (temp_head)
        {
            new_nodes[temp_head]->next = new_nodes[temp_head->next];
            new_nodes[temp_head]->random = new_nodes[temp_head->random];
            temp_head = temp_head->next;
        }

        return new_nodes[head];
    }
};
