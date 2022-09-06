#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    BinaryTreeNode<int> *node=root;
    vector<vector<int>>ans;
    if(root==NULL) return ans;

    vector<int>in;
    vector<int>pre;
    vector<int>post;
    stack<pair<BinaryTreeNode<int> *,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto top=st.top();
        st.pop();
        if(top.second==1){
            pre.push_back(top.first->data);
            top.second++;
            st.push(top);
            if(top.first->left!=NULL){
                st.push({top.first->left,1});
            }
        }
        
        else if(top.second==2){
            in.push_back(top.first->data);
            top.second++;
            st.push(top);
                        if(top.first->right!=NULL){
                st.push({top.first->right,1});
            }
        }
        else
            post.push_back(top.first->data);
    }
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
    
}
