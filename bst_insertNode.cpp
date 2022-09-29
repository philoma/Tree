#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(root==NULL) return new TreeNode<int>(val);
    TreeNode<int>*node=root;
    while(true){
        
        if(val>node->val){
            if(node->right==NULL) {
                node->right=new TreeNode<int>(val);
                break;}else
            {node=node->right;}
        }else{
            if(node->left==NULL){
                node->left=new TreeNode<int>(val);
                break;
            }else
            {node=node->left;}
        }
    }
    return root;
}
