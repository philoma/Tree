class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& v) {
        
        TreeNode*root=new TreeNode(v[0]);
        TreeNode*node=root;
        for(int i=1;i<v.size();i++){
            TreeNode*p=new TreeNode(v[i]);
            node=root;
            while(node){
                if(node->val>p->val){
                    if(node->left==NULL){
                        node->left=p;
                    node=root;
                    break;}
                    node=node->left;
                    
                }else{
                    if(node->right==NULL){
                        node->right=p;
                    node=root;
                    break;}
                    node=node->right;
                }
            }
        }
        return root;
    }
};










class Solution {
public:
    TreeNode* solve(vector<int>& preorder , int mini , int maxi , int &i){
        //base cases
        if(i >= preorder.size())
            return NULL;
        
        if(preorder[i] < mini || preorder[i] > maxi)
            return NULL;
        
        TreeNode* temp = new TreeNode(preorder[i++]);
        temp->left = solve(preorder , mini , temp->val , i);
        temp->right = solve(preorder , temp->val , maxi , i);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder , INT_MIN , INT_MAX , i);
    }
};
