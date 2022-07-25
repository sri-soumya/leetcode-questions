#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int y) {
        
        int n=arr.size();
        priority_queue<pii> q;
        
        for(int i=0;i<n;i++)
        {
            int x=abs(y-arr[i]);
            if(q.size()<k)
            {
                q.push({x,i});
                continue;
            }
            //cout<<i<<" "<<x<<" "<<q.top().ff<<endl;
            if(x<q.top().ff)
            {
                q.pop();
                q.push({x,i});
            }
        }
        
        vector<int> ans;
        
        while(q.size())
        {
            ans.push_back(arr[q.top().ss]);
            q.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};