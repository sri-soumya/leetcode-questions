/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* node,int k,vector<int> &ans,TreeNode* p,map<TreeNode*,TreeNode*> &mp)
    {
        if(!node||k<0)
            return;
        
        if(!k)
            ans.push_back(node->val);
        
        if(node->left!=p)
            dfs(node->left,k-1,ans,node,mp);
        
        if(node->right!=p)
            dfs(node->right,k-1,ans,node,mp);
        
        if(mp[node]!=p)
            dfs(mp[node],k-1,ans,node,mp);
        
    }
    
    void parent(TreeNode* root, map<TreeNode*,TreeNode*> &mp,TreeNode* p)
    {
        if(!root)
            return;
        
        mp[root]=p;
        
        parent(root->left,mp,root);
        parent(root->right,mp,root);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*,TreeNode*> mp;
        parent(root,mp,NULL);
        
        vector<int> ans;
        dfs(target,k,ans,NULL,mp);
        
        return ans;
    }
};