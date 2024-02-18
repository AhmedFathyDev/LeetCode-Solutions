class Solution
{
private:
    vector<vector<int>> levels;

    void level_order(vector<TreeNode *> level_nodes)
    {
        if (!level_nodes.size())
            return;

        vector<TreeNode *> children_nodes;
        vector<int> level;

        for (auto node : level_nodes)
        {
            level.push_back(node->val);

            if (node->left)
                children_nodes.push_back(node->left);

            if (node->right)
                children_nodes.push_back(node->right);
        }

        levels.push_back(level);
        level_order(children_nodes);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return levels;

        level_order({root});
        return levels;
    }
};
