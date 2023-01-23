class Solution {
public:
    
    bool check(TreeNode* root, long mini, long maxi){
        if(root==NULL) return 1;
        
        if(root->val<=mini||root->val>=maxi) return 0;
        
        return check(root->left,mini, root->val) && check(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/
