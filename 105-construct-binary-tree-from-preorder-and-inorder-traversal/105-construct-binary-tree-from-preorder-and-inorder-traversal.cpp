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
    
    TreeNode* solve(vector<int> &a,vector<int> &b,int pi,int ii,int pj,int ij)
    {
        if(pi<0||ii<0||pi>pj||ii>ij)
            return NULL;
        
        TreeNode* t=new TreeNode(a[pi]);
        
        int x=ii;
        for(;x<=ij;x++)
        {
            if(b[x]==a[pi])
                break;
        }
        
        int l=x-ii;
        
        x--;
        t->left=solve(a,b,pi+1,ii,pi+l,x);
        t->right=solve(a,b,pi+l+1,x+2,pj,ij);
        
        return t;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        return solve(preorder,inorder,0,0,n-1,n-1);
        
    }
};