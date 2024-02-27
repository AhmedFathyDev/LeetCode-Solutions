class Solution
{
private:
    vector<int> tree_in_order;

    void in_order(TreeNode *tree)
    {
        if (!tree)
            return;

        in_order(tree->left);

        tree_in_order.push_back(tree->val);

        in_order(tree->right);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        in_order(root);

        return tree_in_order[k - 1];
    }
};
