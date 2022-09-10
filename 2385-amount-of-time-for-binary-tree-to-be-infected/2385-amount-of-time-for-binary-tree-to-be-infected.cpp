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
    
    void parent(TreeNode* root, map<TreeNode*,TreeNode*> &mp,TreeNode* p)
    {
        if(!root)
            return;
        
        mp[root]=p;
        
        parent(root->left,mp,root);
        parent(root->right,mp,root);
        
    }
    
    TreeNode* search(TreeNode* root,int x)
    {
        if(!root)
            return NULL;
        
        if(root->val==x)
            return root;
        
        auto l=search(root->left,x);
        
        if(l)
            return l;
        
        return search(root->right,x);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        parent(root,mp,NULL);
        map<TreeNode*,int> mp1;
        int c=-1;
        
        auto node=search(root,start);
        
        queue<TreeNode*> q;
        q.push(node);
        mp1[node]++;
        while(q.size())
        {
            c++;
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                auto t=q.front();
                q.pop();
                if(t->left&&!mp1.count(t->left))
                {
                    q.push(t->left);
                    mp1[t->left]++;
                }
                if(t->right&&!mp1.count(t->right))
                {
                    q.push(t->right);
                    mp1[t->right]++;
                    
                }
                if(mp[t]&&!mp1.count(mp[t]))
                {
                    q.push(mp[t]);
                    mp1[mp[t]]++;
                }
            }
        }
        
        return c;
    }
};