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
    
    void solve(TreeNode* root,int t,ll s,unordered_map<ll,int> &mp,int &c)
    {
        if(!root)
            return;
        s+=root->val;
        
        c+=mp[s-t];
        
        mp[s]++;
        
        solve(root->left,t,s,mp,c);
        solve(root->right,t,s,mp,c);
        
        mp[s]--;
    }
    
    int pathSum(TreeNode* root, int t) {
        
        int c=0;
        unordered_map<ll,int> mp;
        mp[0]++;
        
        solve(root,t,0ll,mp,c);
        
        return c;
    }
};