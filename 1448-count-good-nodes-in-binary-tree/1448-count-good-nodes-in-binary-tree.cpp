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
    
    int solve(TreeNode* root,int p)
    {
        if(!root)
            return 0;
        
        int x=solve(root->left,max(root->val,p))+solve(root->right,max(root->val,p));
        if(root->val>=p)
            x++;
        return x;
    }
    
    int goodNodes(TreeNode* root) {
        
        return solve(root,INT_MIN);
        
    }
};