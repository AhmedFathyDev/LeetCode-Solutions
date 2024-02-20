class Solution
{
private:
    vector<int> rightView;

    void level_order(vector<TreeNode *> level_nodes)
    {
        if (!level_nodes.size())
            return;

        rightView.push_back(level_nodes.back()->val);
        vector<TreeNode *> children_nodes;

        for (auto node : level_nodes)
        {
            if (node->left)
                children_nodes.push_back(node->left);

            if (node->right)
                children_nodes.push_back(node->right);
        }

        level_order(children_nodes);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return rightView;

        level_order({root});

        return rightView;
    }
};
