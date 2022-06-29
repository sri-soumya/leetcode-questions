class Solution {
public:
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),compare);
        int n=a.size(),c=0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int j,x=0;
            for(j=0;j<ans.size();j++)
            {
                if(x==a[i][1])
                    break;
                if(ans[j][0]>=a[i][0])
                    x++;
            }
            
            ans.insert(ans.begin()+j,a[i]);
        }
        
        return ans;
    }
};