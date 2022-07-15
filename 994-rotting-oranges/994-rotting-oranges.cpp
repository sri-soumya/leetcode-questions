class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size(),f=0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==2)
                    q.push({i,j});
                if(a[i][j]==1)
                    f++;
            }
        }
        
        int c=-1;
        while(q.size())
        {
            c++;
            int l=q.size();
            for(int k=0;k<l;k++)
            {
                auto t=q.front();
                q.pop();
                int x=t.first,y=t.second;
                
                a[x][y]=2;
                
                vector<int> di={-1,0,0,1};
                vector<int> dj={0,-1,1,0};
                
                for(int z=0;z<4;z++)
                {
                    int idi=x+di[z],jdj=y+dj[z];
                    if(idi>=0&&idi<m&&jdj>=0&&jdj<n&&a[idi][jdj]==1)
                    {
                        a[idi][jdj]=2;
                        q.push({idi,jdj});
                        f--;
                    }
                }
            }
        }
        
        if(f)
            return -1;
        
        return max(c,0);
        
    }
};