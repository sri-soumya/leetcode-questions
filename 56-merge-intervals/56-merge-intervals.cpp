class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        vector<pair<int,int>> a;
        
        for(int i=0;i<n;i++)
        {
            a.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(a.begin(),a.end());
        vector<vector<int>> b;
        
        for(int i=0;i<n;i++)
        {
            int x=a[i].first;
            int y=a[i].second;
            
            while(i<n-1&&y>=a[i+1].first)
            {
                i++;
                y=max(y,a[i].second);
            }
            
            b.push_back({x,y});
        }
        
        return b;
        
    }
};