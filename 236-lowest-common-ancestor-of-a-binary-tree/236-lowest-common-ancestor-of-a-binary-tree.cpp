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
    
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(!root)
            return NULL;
        if(p==root||q==root)
            return root;
        
        TreeNode* l=solve(root->left,p,q);
        TreeNode* r=solve(root->right,p,q);
        
        if(!l&&!r)
            return NULL;
        
        if(l&&!r)
            return l;
        if(!l&&r)
            return r;
        
        return root;
        
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
        
        
    }
};