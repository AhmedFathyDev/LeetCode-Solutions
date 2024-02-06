class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *right = invertTree(root->left);
        TreeNode *left = invertTree(root->right);

        root->right = right;
        root->left = left;

        return root;
    }
};
