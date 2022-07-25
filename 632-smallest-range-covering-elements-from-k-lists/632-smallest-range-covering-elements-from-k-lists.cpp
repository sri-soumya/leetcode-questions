#define pii pair<int,pair<int,int>>
#define ff first
#define ss second
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        
        int m=a.size(),mini=INT_MAX,maxi=INT_MIN;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        
        for(int i=0;i<m;i++)
        {
            mini=min(mini,a[i][0]);
            maxi=max(maxi,a[i][0]);
            q.push({a[i][0],{i,0}});
        }
        int start=mini,end=maxi;
        while(q.size())
        {
            auto t=q.top();
            q.pop();
            
            mini=t.ff;
            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            
            int nc=t.ss.ss+1;
            int r=t.ss.ff;
            if(nc>=a[r].size())
                break;
            
            maxi=max(maxi,a[r][nc]);
            q.push({a[r][nc],{r,nc}});
        }
        
        return {start,end};
    }
};