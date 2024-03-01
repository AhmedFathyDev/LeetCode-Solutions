class Solution
{
private:
    map<int, int> inorder_indices;

    TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                        vector<int> &inorder, int in_start, int in_end)
    {
        if (pre_start > pre_end || in_start > in_end)
            return NULL;

        TreeNode *node = new TreeNode(preorder[pre_start]);

        int in_node_index = inorder_indices[preorder[pre_start]];
        int left_nodes = in_node_index - in_start;

        node->left = buildTree(preorder, pre_start + 1, pre_start + left_nodes,
                               inorder, in_start, in_node_index - 1);

        node->right = buildTree(preorder, pre_start + left_nodes + 1, pre_end,
                                inorder, in_node_index + 1, in_end);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int nodes_count = inorder.size();

        for (int i = 0; i < nodes_count; ++i)
            inorder_indices[inorder[i]] = i;

        return buildTree(preorder, 0, nodes_count - 1, inorder, 0, nodes_count - 1);
    }
};
