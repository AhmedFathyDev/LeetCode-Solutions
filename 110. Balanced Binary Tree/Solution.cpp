class Solution
{
private:
    int height(TreeNode *tree)
    {
        if (!tree)
            return 0;

        return max(height(tree->left), height(tree->right)) + 1;
    }

    int balance_factor(TreeNode *tree)
    {
        if (!tree)
            return 0;

        return height(tree->left) - height(tree->right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        return abs(balance_factor(root)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
