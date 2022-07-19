class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        ans[0]={1};
        for(int i=1;i<n;i++)
        {
            vector<int> b;
            for(int j=0;j<=i;j++)
            {
                int l=(j-1>=0)?ans[i-1][j-1]:0;
                int r=(j<=i-1)?ans[i-1][j]:0;
                b.push_back(l+r);
                
            }
            
            ans[i]=b;
        }
        
        return ans;
    }
};