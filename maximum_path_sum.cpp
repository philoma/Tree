#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

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
int maxPathDown(TreeNode<int> *node, int &maxi){
    
    if(node==NULL) return 0;
    int left=max(0,maxPathDown(node->left, maxi));
    
    int right=max(0,maxPathDown(node->right, maxi));
    maxi=max(maxi, left+node->data+right);
    
return max(left, right)+node->data;
    
}
int maxPathSum(TreeNode<int> *root)
{
    // Write your code here
    int maxi=INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
    
    
}
