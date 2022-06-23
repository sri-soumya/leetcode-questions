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
    
    int solve(TreeNode* root,map<int,int> &mp,int &c)
    {
        if(!root)
            return 0;
        
        int s=root->val+solve(root->left,mp,c)+solve(root->right,mp,c);
        mp[s]++;
        c=max(c,mp[s]);
        return s;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<int,int> mp;
        int c=0;
        solve(root,mp,c);
        vector<int> ans;
        
        for(auto i:mp)
        {
            if(i.second==c)
                ans.push_back(i.first);
        }
        
        return ans;
    }
};