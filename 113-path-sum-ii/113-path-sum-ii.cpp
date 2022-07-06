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
    
    void solve(TreeNode* root,int t,vector<int> &a,vector<vector<int>> &b)
    {
        if(!root)
            return;
        if(!root->left&&!root->right)
        {
            if(t==root->val)
            {
                a.push_back(root->val);
                b.push_back(a);
                a.pop_back();
            }
            return;
        }
        //cout<<root->val<<" "<<t<<endl;
        
        
        a.push_back(root->val);
        solve(root->left,t-root->val,a,b);
        solve(root->right,t-root->val,a,b);
        
        a.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        
        vector<int> a;
        vector<vector<int>> b;
        
        solve(root,t,a,b);
        return b;
        
    }
};