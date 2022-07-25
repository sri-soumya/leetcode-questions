#define pii pair<double,int>
#define ff first
#define ss second
#define ll long long int
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     
        priority_queue<pii> q;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            double d=sqrt(((ll)points[i][0])*points[i][0]+((ll)points[i][1])*points[i][1]);
            if(q.size()<k)
                q.push({d,i});
            else if(d<q.top().ff)
            {
                q.pop();
                q.push({d,i});
            }
        }
        
        vector<vector<int>> ans;
        
        while(q.size())
        {
            ans.push_back(points[q.top().ss]);
            q.pop();
        }
        
        return ans;
    }
};