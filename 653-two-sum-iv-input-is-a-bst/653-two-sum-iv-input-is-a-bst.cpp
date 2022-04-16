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

class iter{
    public:
    stack<TreeNode*> *s;
    stack<TreeNode*> *p;
    iter(TreeNode* root) {
        s=new stack<TreeNode*>();
        p=new stack<TreeNode*>();
        TreeNode* t=root;
        while(t)
        {
            s->push(t);
            t=t->left;
        }
        t=root;
        while(t)
        {
            p->push(t);
            t=t->right;
        }
    }
    
    int next() {
        TreeNode* t=s->top();
        s->pop();
        int tt=t->val;
        t=t->right;
        while(t)
        {
            s->push(t);
            t=t->left;
        }
        return tt;
    }
    
    int prev()
    {
        TreeNode* t=p->top();
        p->pop();
        int tt=t->val;
        t=t->left;
        while(t)
        {
            p->push(t);
            t=t->right;
        }
        return tt;
    }
    
    
    bool hasNext() {
        return s->size();
    }
    
    bool hasPrev()
    {
        return p->size();
    }
    
    TreeNode* stop()
    {
        return s->top();
    }
    
    TreeNode* ptop()
    {
        return p->top();
    }
};

class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        iter *o=new iter(root);
        
        while(o->hasNext()&&o->hasPrev())
        {
            int a=o->stop()->val,b=o->ptop()->val;
            if(a+b==k&&o->stop()!=o->ptop())
                return true;
            else if(a+b<k)
                o->next();
            else
                o->prev();
        }
        
        return false;
    }
};