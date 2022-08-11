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
#define ll long long int
class Solution {
public:
    
    bool solve(TreeNode* root,ll l,ll u)
    {
        if(!root)
            return true;
        
        if(root->val<=l||root->val>=u)
            return false;
        
        return solve(root->left,l,root->val)&&solve(root->right,root->val,u);
    }
    
    bool isValidBST(TreeNode* root) {
        
        return solve(root,LONG_MIN,LONG_MAX);
        
    }
};