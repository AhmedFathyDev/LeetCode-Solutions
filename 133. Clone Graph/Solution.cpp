class Solution
{
private:
    Node *dfs(Node *oldNode, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> neighbors;

        Node *newNode = new Node(oldNode->val);
        mp[oldNode] = newNode;

        for (Node *neighbor : oldNode->neighbors)
            if (mp.find(neighbor) != mp.end())
                neighbors.push_back(mp[neighbor]);
            else
                neighbors.push_back(dfs(neighbor, mp));

        newNode->neighbors = neighbors;
        return newNode;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        if (node->neighbors.size() == 0)
            return new Node(node->val);

        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};
