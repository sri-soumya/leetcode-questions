class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> a;
        a.push_back({1});
        
        for(int i=1;i<n;i++)
        {
            vector<int> b(i+1,0);
            
            for(int j=0;j<=i;j++)
            {
                int l=(j-1>=0)?a[i-1][j-1]:0;
                int r=(j<=i-1)?a[i-1][j]:0;
                b[j]=l+r;
            }
            
            a.push_back(b);
        }
        
        return a;
    }
};