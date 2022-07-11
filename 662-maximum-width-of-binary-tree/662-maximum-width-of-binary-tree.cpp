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
#define ll unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=0;
        
        while(q.size())
        {
            int n=q.size();
            ll l=q.front().second,r=0;
            for(int i=0;i<n;i++)
            {
                auto t=q.front();
                q.pop();
                
                if(t.first->left)
                {
                    q.push({t.first->left,t.second*2+1});
                }
                if(t.first->right)
                {
                    q.push({t.first->right,t.second*2+2});
                }
                if(i==n-1)
                    r=t.second;
            }
            
            ans=max(ans,(r-l));
        }
        
        return ans+1;
    }
};