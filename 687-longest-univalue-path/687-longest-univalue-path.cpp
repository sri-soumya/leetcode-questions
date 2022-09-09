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
    
    int solve(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        
        int ls=0,rs=0;
        
        if(root->left&&root->left->val==root->val)
            ls=l+1;
        
        if(root->right&&root->right->val==root->val)
            rs=r+1;
        
        ans=max(ans,ls+rs);
        
        return max(ls,rs);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        int ans=0;
        
        solve(root,ans);
        
        return ans;
        
    }
};