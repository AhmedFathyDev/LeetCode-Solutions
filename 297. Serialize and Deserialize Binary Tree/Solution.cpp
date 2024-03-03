class Codec
{
private:
    TreeNode *deserialize(queue<string> &nodes)
    {
        string val = nodes.front();
        nodes.pop();

        if (val == "null")
            return NULL;

        TreeNode *node = new TreeNode(stoi(val));

        node->left = deserialize(nodes);
        node->right = deserialize(nodes);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null,";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> nodes;
        int data_length = data.size();

        for (int i = 0, start_index = 0; i < data_length; ++i)
            if (data[i] == ',')
            {
                string sub_string = "";
                sub_string.append(data, start_index, i - start_index);
                nodes.push(sub_string);
                start_index = i + 1;
            }

        return deserialize(nodes);
    }
};
