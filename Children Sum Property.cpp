/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (root->data <= child)
        root->data = child;
    else
    {
        if (root->left) 
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    // reorder
    changeTree(root->left);
    changeTree(root->right);

    // backtrack

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    // non leaf nodes-
    if (root->left || root->right)
        root->data = tot;
}
