class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int t) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                set<int> s;
                int x=0;
                s.insert(0);
                for(int k=0;k<m;k++)
                {
                    //x+=0;
                    x+=matrix[k][j]-((i-1>=0)?matrix[k][i-1]:0);
                    // if(x<=t)
                    //     ans=max(ans,x);
                    //else
                    {
                        auto it=s.lower_bound(x-t);
                        if(it!=s.end())
                            ans=max(ans,x-*it);
                    }
                    s.insert(x);
                }
            }
        }
        
        return ans;
    }
};