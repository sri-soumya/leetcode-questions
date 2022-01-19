class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> a;
        
        int n=intervals.size();
        
        for(int i=0;i<n;i++)
        {
            a.push_back({intervals[i][0],intervals[i][1]});
        }
        
        sort(a.begin(),a.end());
        
        vector<pair<int,int>> b;
        
        for(int i=0;i<n;i++)
        {
            int s=a[i].first,maxi=a[i].second;
            while(i<n-1&&maxi>=a[i+1].first)
            {
                i++;
                maxi=max(maxi,a[i].second);
            }
            
            b.push_back({s,maxi});
        }
        
        vector<vector<int>> c;
        
        for(int i=0;i<b.size();i++)
        {
            c.push_back({b[i].first,b[i].second});
        }
        
        return c;
    }
};