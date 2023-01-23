
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;;
    while(node){
        if(node->data==x) return x;
        if(x>node->data){
            node=node->right;
            
        }else{
            ceil=node->data;
            node=node->left;
            
        }
       
    }
    return ceil;
}

//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
