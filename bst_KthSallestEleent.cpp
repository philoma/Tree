#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
int h=0;
void dfs(BinaryTreeNode<int>* root, int k,int& val) {
   if(root==NULL) 
        return;
    
    
    dfs(root->left,k,val);
     val++;
    if(k==val) {
        h=root->data;
        return;
    }
    dfs(root->right, k,val);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    //inorder traversal in bst is always in sorted manner
    int val=0;
    h=-1;
    dfs(root,k,val);
    if(val==0)
        return -1;
    return h;
    }
