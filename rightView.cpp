/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> printRightView(BinaryTreeNode<int>* root)
{
    //    Write your code here
    vector<int> ans;
    if (!root)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            if (i == size-1)
            {
                ans.push_back(node->data);
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    return ans;
}



//right side view











void f(TreeNode* root, vector<int>&ans, int level){
        if(root==NULL) return;
        
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        if(root->right){
            f(root->right, ans, level+1);
        }
        if(root->left){
            f(root->left, ans, level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level=0;
        f(root,ans, level);
        return ans;
    }
