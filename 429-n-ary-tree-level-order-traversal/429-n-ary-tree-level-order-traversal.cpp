/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(q.size())
        {
            int n=q.size();
            vector<int> a;
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                a.push_back(x->val);
                for(auto y:x->children)
                    q.push(y);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};