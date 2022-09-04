#include<stack>
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

vector<int> preorderTraversal(TreeNode* root)
{
    // Write your code here	
    //iterative method
    vector<int>ans;
    if(root==NULL) return ans;
    
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* top=st.top();
        st.pop();
        ans.push_back(top->val);
        if(top->right!=NULL) st.push(top->right);
        if(top->left!=NULL) st.push(top->left);
    }
    return ans;
}
