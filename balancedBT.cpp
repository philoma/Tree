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
//O(n) space
int dfsheight(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    int lh=dfsheight(root->left);
    if(lh==-1) return -1;
    int rh=dfsheight(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
    
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return dfsheight(root) !=-1;
}
