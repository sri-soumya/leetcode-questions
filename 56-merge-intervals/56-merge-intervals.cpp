class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        sort(a.begin(),a.end());
        
        vector<vector<int>> ans;
        vector<int> b;
        b=a[0];
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i][0]<=b[1])
            {
                b[0]=min(b[0],a[i][0]);
                b[1]=max(b[1],a[i][1]);
            }
            else
            {
                ans.push_back(b);
                b=a[i];
            }
        }
        ans.push_back(b);
        return ans;
    }
};