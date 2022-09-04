#define ff first
#define ss second
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(q.size())
        {
            auto x=q.front().ff;
            auto y=q.front().ss;
            q.pop();
            if(x->left)
                q.push({x->left,{y.ff-1,y.ss+1}});
            if(x->right)
                q.push({x->right,{y.ff+1,y.ss+1}});
            
            mp[y.ff][y.ss].insert(x->val);
        }
        
        vector<vector<int>> ans;
        
        for(auto x:mp)
        {
            
            vector<int> a;
            
            for(auto y:x.ss)
            {
                for(auto z:y.ss)
                    a.push_back(z);
            }
            
            ans.push_back(a);
        }
        
        return ans;
        
    }
};