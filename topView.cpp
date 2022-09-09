#include <bits/stdc++.h>

// find() in map is used to search for the key-value pair and accepts the “key” in its argument to find it. This function returns the pointer to the element if the element is found, else it returns the pointer pointing to the last position of map i.e “map.end()” .
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    TreeNode<int> *node = root;

    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;

    q.push({root, 0});
    int line = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode<int> *node = it.first;
        // agar line(key) already na hui tab hi ye new key value pairs dalega wrna ignore krdega
        int line = it.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->val;
        }
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    for (itr : mp)
    {
        ans.push_back(itr.second);
    }
    return ans;
}
