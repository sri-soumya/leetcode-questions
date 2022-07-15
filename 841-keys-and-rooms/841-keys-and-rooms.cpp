class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<bool> v(n,0);
        
        queue<int> q;
        q.push(0);
        int c=0;
        while(q.size())
        {
            int x=q.front();
            q.pop();
            if(v[x])
                continue;
            v[x]=true;
            c++;
            for(auto ve:a[x])
            {
                if(!v[ve])
                    q.push(ve);
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     if(!v[i])
        //         return false;
        // }
        
        return c==n;
        
    }
};