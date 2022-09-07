/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    bool flag = 1;
    while (!q.empty())
    {
        
            int size = q.size();
        vector<int>level;
            for (int i = 0; i < size; i++)
            {
                TreeNode<int> *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                level.push_back(node->data);
            }
        flag=!flag;
        if(flag){
            reverse(level.begin(), level.end());
        }
        for(int i=0;i<level.size();i++){
            ans.push_back(level[i]);
        }
            
    }

    return ans;
}
