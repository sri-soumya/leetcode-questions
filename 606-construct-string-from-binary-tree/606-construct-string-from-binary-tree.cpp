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
    
    string solve(TreeNode* root)
    {
        if(!root)
            return "";
        string l=solve(root->left);
        string r=solve(root->right);
        
        string a=to_string(root->val);
        if(!l.size()&&!r.size())
            return a;
        a+="("+l+")";
        if(r.size())
            a+="("+r+")";
        return a;
    }
    
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};