#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
     vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode<int>*, int>>q;
        map<int, list<int>>mp;
        q.push({root, 0});
        while(!q.empty()){
            auto it=q.front(); q.pop();
            TreeNode<int>*node=it.first;
            int line=it.second;
            mp[line].push_back(node->data);
            if(node->left!=NULL) q.push({node->left, line-1});
            if(node->right!=NULL) q.push({node->right, line+1});
            
        }
        for(auto it: mp){
            
            for(auto jt:it.second){
                ans.push_back(jt);
            }
            
        }
       return ans; 
}


//link: https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
