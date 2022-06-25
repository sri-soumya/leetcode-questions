class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<vector<int>> sd(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        // vector<int> dx={-1,-1,-1,0,0},dy={-1,0,1,}
        if(a[0][0]==0)
        {
            q.push({0,0});
            sd[0][0]=0;
        }
        
        while(q.size())
        {
            int i=q.front().first,j=q.front().second;
            int d=sd[i][j]+1;
            q.pop();
            for(int dx=-1;dx<=1;dx++)
            {
                for(int dy=-1;dy<=1;dy++)
                {
                    if(i+dx<0||i+dx>=n||j+dy<0||j+dy>=n)
                        continue;
                    if((dx==0&&dy==0)||a[i+dx][j+dy])
                        continue;
                    if(d<sd[i+dx][j+dy])
                    {
                        sd[i+dx][j+dy]=d;
                        q.push({i+dx,j+dy});
                    }
                }
            }
            
        }
        
        if(sd[n-1][n-1]==INT_MAX)
            return -1;
        return sd[n-1][n-1]+1;
        
    }
};