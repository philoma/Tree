#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector << vector < int >> levelorder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) // ran loop to store elements of each respective levels
            {
                int TreeNode *front = q.front();
                q.pop();
                level.push_back(front->data);
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(level);
        }
    }
} int main()
{

    return 0;
}




//if asked to store traversal linearly
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *node=q.front();
        q.pop();        
        if(node->left!=NULL) {q.push(node->left);}
        if(node->right!=NULL) {q.push(node->right);}
        
        ans.push_back(node->val);
    }
    return ans;
}
