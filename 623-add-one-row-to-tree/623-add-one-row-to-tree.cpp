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
    
    void solve(TreeNode* root,int val,int depth)
    {
        if(!root||depth<=0)
            return;
        if(depth==1)
        {
            TreeNode* nl=new TreeNode(val);
            nl->left=root->left;
            TreeNode* nr=new TreeNode(val);
            nr->right=root->right;
            root->left=nl;
            root->right=nr;
        }    
        
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth--;
        if(!depth)
        {
            TreeNode* nh=new TreeNode(val);
            nh->left=root;
            return nh;
        }
        
        solve(root,val,depth);
        return root;
    }
};