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
    
    int solve(TreeNode* root,int p,map<pair<TreeNode*,int>,int> &dp)
    {
        if(!root)
            return 0;
        
        if(dp.count({root,p}))
            return dp[{root,p}];
        
        if(p)
            return dp[{root,p}]= solve(root->left,0,dp)+solve(root->right,0,dp);
        
        int op1=solve(root->left,0,dp)+solve(root->right,0,dp);
        int op2=solve(root->left,1,dp)+solve(root->right,1,dp)+root->val;
        
        return dp[{root,p}]=  max(op1,op2);
        
    }
    
    int rob(TreeNode* root) {
        
        map<pair<TreeNode*,int>,int> dp;
        
        return solve(root,0,dp);
        
    }
};