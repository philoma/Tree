#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void reverse_post_order(TreeNode<int> *&node,TreeNode<int>*&prev ){
    if(node==NULL) return;
    reverse_post_order(node->right, prev);
    reverse_post_order(node->left, prev);
    node->right=prev;
    node->left=NULL;
    prev=node;

}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    TreeNode<int> *prev=NULL;
    reverse_post_order(root, prev);
    return root;
}

// https://www.codingninjas.com/codestudio/problems/1112615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
