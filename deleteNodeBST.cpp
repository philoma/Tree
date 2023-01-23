class Solution {
public:
    TreeNode*rightest(TreeNode*root){
        if(root->right==NULL) return root;
        
        return rightest(root->right);
    }
    TreeNode* attach(TreeNode*root){
        
        //if left ya right sub tree ho hi na
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
        //if both subtrees he prsnt then-
        TreeNode*rightchild=root->right;
        TreeNode*lastright=rightest(root->left);
        lastright->right=rightchild;
        
        return root->left;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return root;
        
        //if root hi delete krni ho
        if(root->val==key) return attach(root);
        
        TreeNode*node=root;
        
        while(node){
            if(node->val>key){
                if(node->left!=NULL&& node->left->val==key){
                    node->left=attach(node->left);
                    break;
                }else{
                   node=node->left; 
                }
            }else{
                if(node->right!=NULL && node->right->val==key){
                    node->right=attach(node->right);
                    
                }else{
                    node=node->right;
                }
            }
        }
        return root;
    }
};
