vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    
    vector<int>ans;
    if(root==NULL) return ans;
    
    queue<pair<BinaryTreeNode<int> *, int>>q;
    q.push({root, 0});
    map<int, int>mp;
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        BinaryTreeNode<int> *node=it.first;
        
       int line=it.second;
       mp[line]=node->data;
        
        if(node->left!=NULL) {
            q.push({node->left, line-1});
        }
        if(node->right!=NULL){
            q.push({node->right, line+1});
        }
    }
    for(auto itr: mp){
        ans.push_back(itr.second);
    }
    return ans;
}
