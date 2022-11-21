class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        
        queue<vector<int>> q;
        q.push(entrance);
        int c=0;
        
        while(q.size())
        {
            int num=q.size();
            for(int i=0;i<num;i++)
            {
                auto x=q.front();
                q.pop();
                if(x[0]<0||x[1]<0||x[0]>=n||x[1]>=m||maze[x[0]][x[1]]=='+')
                    continue;
                if((x[0]==0||x[1]==0||x[0]==n-1||x[1]==m-1)&&(x[0]!=entrance[0]||x[1]!=entrance[1]))
                    return c;
                maze[x[0]][x[1]]='+';
                q.push({x[0]+1,x[1]});
                q.push({x[0]-1,x[1]});
                q.push({x[0],x[1]+1});
                q.push({x[0],x[1]-1});
                
            }
            c++;
        }
        
        return -1;
    }
};