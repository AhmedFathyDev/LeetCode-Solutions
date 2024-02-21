class Solution
{
private:
    int goodNodes(TreeNode *node, int max)
    {
        if (!node)
            return 0;

        bool is_good = false;

        if (node->val >= max)
        {
            is_good = true;
            max = node->val;
        }

        return (is_good ? 1 : 0) + goodNodes(node->left, max) + goodNodes(node->right, max);
    }

public:
    int goodNodes(TreeNode *root)
    {
        return goodNodes(root, root->val);
    }
};
