/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    void in_order(TreeNode *tree, vector<int> &in_ord)
    {
        if (tree != NULL)
        {
            in_order(tree->left, in_ord);
            in_ord.push_back(tree->val);
            in_order(tree->right, in_ord);
        }
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> in_ord;
        in_order(root, in_ord);

        int i = 0;
        int j = in_ord.size() - 1;

        while (i < j)
            if (in_ord[i] + in_ord[j] < k)
                ++i;
            else if (in_ord[i] + in_ord[j] == k)
                return true;
            else
                --j;

        return false;
    }
};
