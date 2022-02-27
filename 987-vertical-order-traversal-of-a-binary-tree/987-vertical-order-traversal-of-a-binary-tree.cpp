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
#define ff first
#define ss second
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> x;
        //return ans;
        q.push({root,{0,0}});
        while(q.size())
        {
            TreeNode* t=q.front().first;
            int xc=q.front().second.first;
            int yc=q.front().second.second;
            q.pop();
            x[xc][yc].insert(t->val);
            if(t->left)
                q.push({t->left,{xc-1,yc+1}});
            if(t->right)
                q.push({t->right,{xc+1,yc+1}});
        }
        
        for(auto i:x)
        {
            vector<int> a;
            for(auto j:i.second)
            {
                for(auto k:j.second)
                    a.push_back(k);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};