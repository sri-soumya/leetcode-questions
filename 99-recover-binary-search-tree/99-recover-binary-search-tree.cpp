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
    
    
    void solve(TreeNode* root,TreeNode* &p,TreeNode* &f,TreeNode* &s,TreeNode* &l)
    {
        if(!root)
        {
            //p=root;
            return;
        }
        // cout<<root->val<<endl;
        solve(root->left,p,f,s,l);
        if(p&&p->val>=root->val)
        {
            //cout<<p->val<<endl;
            if(!f)
            {
                f=p;
                s=root;
            }
            else
                l=root;
        }
        
        p=root;
        solve(root->right,p,f,s,l);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* p=NULL;
        TreeNode* f=NULL;
        TreeNode* s=NULL;
        TreeNode* l=NULL;
        
        solve(root,p,f,s,l);
        
        if(!l)
        {
            swap(f->val,s->val);
            
        }
        else
            swap(f->val,l->val);
    }
};