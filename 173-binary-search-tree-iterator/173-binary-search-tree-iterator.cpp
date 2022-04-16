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
class BSTIterator {
public:
    stack<TreeNode*> *s;
    BSTIterator(TreeNode* root) {
        s=new stack<TreeNode*>();
        TreeNode* t=root;
        while(t)
        {
            s->push(t);
            t=t->left;
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
    
    bool hasNext() {
        return s->size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */