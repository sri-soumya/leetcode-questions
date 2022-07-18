class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        
        int n=a.size(),m=a[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
                a[i][j]+=a[i][j-1];
        }
        
        int c=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                unordered_map<int,int> mp;
                mp[0]=1;
                int s=0;
                for(int k=0;k<n;k++)
                {
                    s+=a[k][j]-((i-1>=0)?a[k][i-1]:0);
                    if(mp.count(s-t))
                        c+=mp[s-t];
                    mp[s]++;
                }
            }
        }
        
        return c;
        
    }
};