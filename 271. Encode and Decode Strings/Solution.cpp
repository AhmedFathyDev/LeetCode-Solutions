class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        string encoded;

        for (string str : strs)
            encoded += str + ';';

        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        vector<string> strs;

        int str_size = str.size();
        string decoded;

        for (int i = 0; i < str.size() - 1; ++i)
            if (str[i] == ';' && str[i + 1] != ';')
                strs.push_back(decoded), decoded.clear();
            else
                decoded += str[i];

        strs.push_back(decoded);

        return strs;
    }
};
