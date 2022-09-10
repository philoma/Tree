 bool help(TreeNode* root1, TreeNode* root2){
        if(root1==NULL||root2==NULL) return root1==root2;
        
        if(root1->val!=root2->val) return 0;
        
        return help(root1->left, root2->right) && help(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL|| help(root->left, root->right);
    }
