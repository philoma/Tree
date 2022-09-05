#include<bits/stdc++.h>
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int>ans;
    
    if(root==NULL) return ans;
    
    TreeNode*node=root;
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(node);
    while(!st1.empty()){
        TreeNode*top=st1.top();
        st1.pop();
        st2.push(top);
        if(top->left!=NULL) st1.push(top->left);
        
        if(top->right!=NULL) st1.push(top->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}
