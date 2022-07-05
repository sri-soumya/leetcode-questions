class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        int n=a.size();
        
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;)
        {
            vector<int> b=a[i];
            for(i=i+1;i<n;i++)
            {
                if(a[i][0]<=b[1])
                {
                    b[1]=max(a[i][1],b[1]);
                }
                else
                    break;
            }
            ans.push_back(b);
        }
        
        return ans;
        
    }
};