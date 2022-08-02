class Solution {
public:
    
    bool check(vector<vector<int>> &matrix,int x,int k)
    {
        int n=matrix.size();
        int cnt=0;
        
        int r=0,c=n-1;
        
        while(r<n)
        {
             while(c>=0&&matrix[r][c]>x)
            {
                c--;
            }
            r++;
            cnt+=c+1;
        }
       
        
        return cnt>=k;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        int ans=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(matrix,m,k))
            {
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        
        return ans;
        
    }
};