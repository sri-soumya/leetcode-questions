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
    bool bst;
    int ma;
    int mi;
    int s;
};

class Solution {
public:
    
    node solve(TreeNode* root,int &ans)
    {
        node ob;
        if(!root)
        {
            ob.bst=true;
            ob.ma=INT_MIN;
            ob.mi=INT_MAX;
            ob.s=0;
            return ob;
        }
        
        auto l=solve(root->left,ans);
        auto r=solve(root->right,ans);
        
        ob.bst=l.bst&&r.bst&&root->val>l.ma&&root->val<r.mi;
        ob.s=root->val+l.s+r.s;
        ob.mi=min(root->val,l.mi);
        ob.ma=max(root->val,r.ma);
        if(ob.bst)
            ans=max(ans,ob.s);
        return ob;
    }
    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};