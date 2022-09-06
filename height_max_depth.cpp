#include<queue>
//TreeNode class definition
/*
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
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

*/
//ercursive
// int findMaxDepth(TreeNode<int> *root) 
// {
// 	//Write your code here.  
//     if(root==NULL) return 0;
    
//     int lh= findMaxDepth(root->left);
//     int rh=findMaxDepth(root->right);
    
//     return 1+(max(rh,lh));
// }




//iterative level order- max depth
 int findMaxDepth(TreeNode<int> *root) {
     int levels=0;
     TreeNode<int> *node=root;
     if(node==NULL) return 0;
     
     queue<TreeNode<int> *>q;
     q.push(node);
     while(!q.empty()){
         
         int size=q.size();
         for(int i=0;i<size;i++){
             TreeNode<int> *node=q.front();
         q.pop();
             
             if(node->left!=NULL)
                 q.push(node->left);
             if(node->right!=NULL)
                 q.push(node->right);
         }
            levels++;
         
     }
    return levels; 
 }

