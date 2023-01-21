/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>>q; //{node, {x,y}}
        map<int, map<int, multiset<int>>>mp;  //{x, {y,(nodes->vals, set me min val top me hoti he, so)}}
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            
            int x=it.second.first;
            int y=it.second.second;
            TreeNode*node=it.first;
            if(node->left!=NULL) q.push({node->left, {x-1, y+1}});
            if(node->right!=NULL) q.push({node->right, {x+1, y+1}});
            mp[x][y].insert(node->val);
            
        }
        
        for(auto it:mp){
            vector<int>v;
            for(auto jt: it.second){
                v.insert(v.end(), jt.second.begin(), jt.second.end());
                // har ek level pr, v ke end me push_back/insert kr rhe he, poora starting se end tak ke multisets
            }
            ans.push_back(v);
        }
        return ans;
    }
};

//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/





























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
