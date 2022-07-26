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
    
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return NULL;
        
        if(root->val==p->val||root->val==q->val)
            return root;
        
        auto l=solve(root->left,p,q);
        auto r=solve(root->right,p,q);
        
        if(!l&&!r)
            return NULL;
        
        if(!l)
            return r;
        
        if(!r)
            return l;
        
        return root;
    }

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return solve(root,p,q);
        
    }
};