class Solution {
public:
    
    void dfs(TreeNode*root, int t){
        if(root==NULL){
            
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(root->val>=t){
                root->left=new TreeNode(t);
            }else root->right=new TreeNode(t);
            
            return;
        }
        else if(root->left==NULL&&root->val>t){
            root->left=new TreeNode(t);
            return;
            
        }else if(root->right==NULL && root->val<t){
            root->right=new TreeNode(t);
            return;
        }
        
        if(t<root->val){
            dfs(root->left, t);
        }else{
            dfs(root->right, t);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int t) {
        
        if(root==NULL){
            TreeNode*node=new TreeNode(t);
            return node;
        }
        dfs(root, t);
        return root;
        
    }
};
























class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        TreeNode*node=root;
        while(node){
            
            if(node->val<=val){
                
                if(node->right==NULL){
                    node->right=new TreeNode(val);
                    break;
                }else{
                    node=node->right;
                }
                
            }else{
                if(node->left==NULL){
                    node->left=new TreeNode(val);
                    break;
                }else{
                    node=node->left;
                }
                
                
            }
        }
        
        return root;
    }
};




// https://leetcode.com/problems/insert-into-a-binary-search-tree/
