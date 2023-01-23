
int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    if(root==NULL) return -1;
    int floor=-1;
    while(root){
        if(root->val==x) return x;
        
        if(x>root->val){
            floor=root->val;
            root=root->right;
           
        }else{
          
            root=root->left;  
        }
    }
    return floor;
}
