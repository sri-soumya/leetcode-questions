class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        
        int t=0,l=0,b=n-1,r=m-1;
        
        vector<int> ans;
        while(t<=b&&l<=r)
        {
            for(int i=l;i<=r;i++)
            {
                ans.push_back(a[t][i]);
            }
            for(int i=t+1;i<=b;i++)
            {
                ans.push_back(a[i][r]);
            }
            if(t!=b)
            {
                for(int i=r-1;i>=l;i--)
                {
                    ans.push_back(a[b][i]);
                }
            }
            if(l!=r)
            {
                for(int i=b-1;i>t;i--)
                {
                    ans.push_back(a[i][l]);
                }
            }
            t++;
            b--;
            l++;
            r--;
        }
        
        return ans;
        
    }
};