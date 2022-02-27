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
    
    int solve(TreeNode* root, bool& f)
    {
        if(!root)
            return 0;
        int l=solve(root->left,f);
        int r=solve(root->right,f);
        f=(f&&abs(l-r)<=1)?true:false;
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool f=true;
        solve(root,f);
        return f;
        
    }
};