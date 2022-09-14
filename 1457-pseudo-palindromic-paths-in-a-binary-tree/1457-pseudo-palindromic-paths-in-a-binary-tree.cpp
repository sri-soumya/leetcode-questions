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
    
    bool check(map<int,int> mp)
    {
        int o=0;
        
        for(auto x:mp)
        {
            o+=x.second%2;
        }
        //cout<<o<<endl;
        return o<=1;
    }
    
    int solve(TreeNode* root,map<int,int> &mp)
    {
        if(!root)
        {
            return 0;
        }
        
        mp[root->val]++;
        
        int c=0;
        if(!root->left&&!root->right)
        {
            c=check(mp);
        }
        else
            c=solve(root->left,mp)+solve(root->right,mp);
        mp[root->val]--;
        return c;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
     
        map<int,int> mp;
        return solve(root,mp);
        
    }
};