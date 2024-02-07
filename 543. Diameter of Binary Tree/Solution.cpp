class Solution
{
private:
    int maxDiameter;

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int maxDepthLeft = maxDepth(root->left);
        int maxDepthRight = maxDepth(root->right);

        maxDiameter = max(maxDiameter, maxDepthLeft + maxDepthRight);

        return max(maxDepthLeft, maxDepthRight) + 1;
    }

public:
    Solution() : maxDiameter(0) {}

    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);

        return maxDiameter;
    }
};
