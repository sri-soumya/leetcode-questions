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
    
    bool isValidBST(TreeNode* root) {

        ll maxi=LONG_MAX,mini=LONG_MIN;
        return solve(root,mini,maxi);
    }
    
    bool solve(TreeNode* root,ll mini,ll maxi) {
        
        if(!root)
            return true;
        if(root->val<=mini||root->val>=maxi)
            return false;
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
    }
};