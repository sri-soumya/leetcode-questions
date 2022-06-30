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


class node{
    public:
    int maxi;
    int mini;
    int h;
    int s;
    bool bst;
    node()
    {
        maxi=INT_MIN;
        mini=INT_MAX;
        h=0;
        s=0;
        bst=true;
    }
};

class Solution {
public:
    
    node solve(TreeNode* root)
    {
        node ans;
        if(!root)
        {
            return ans;
        }
        
        node l=solve(root->left);
        node r=solve(root->right);
        
        //cout<<root->val<<" "<<l.h<<" "<<l.s<<" "<<r.h<<" "<<r.s<<endl;
        
        if(l.maxi>=root->val||r.mini<=root->val||!l.bst||!r.bst)
        {
            ans.maxi=INT_MAX;
            ans.mini=INT_MIN;
            ans.h=max(l.h,r.h);
            ans.s=root->val+l.s,r.s;
            ans.bst=0;
            return ans;
        }
        
        ans.maxi=max(root->val,r.maxi);
        ans.mini=min(root->val,l.mini);
        ans.h=max(root->val+l.s+r.s,max(l.h,r.h));
        ans.s=root->val+l.s+r.s;
        ans.bst=1;
        
        //cout<<root->val<<" "<<ans.h<<" "<<ans.s<<endl;
        
        return ans;
    }
    
    
    int maxSumBST(TreeNode* root) {
        
        return (solve(root).h);
        
    }
};