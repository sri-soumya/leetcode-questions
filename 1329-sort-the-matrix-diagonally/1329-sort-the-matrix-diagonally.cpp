class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
     
        int m=mat.size(),n=mat[0].size();
        
        for(int i=0;i<m;i++)
        {
            int x=i,y=0;
            vector<int> s;
            while(x<m&&y<n)
            {
                s.push_back(mat[x][y]);
                x++;
                y++;
            }
            
            sort(s.begin(),s.end());
            
            x=i,y=0;
            int c=0;
            while(x<m&&y<n)
            {
                mat[x][y]=s[c];
                x++;
                y++;
                c++;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            int x=0,y=i;
            vector<int> s;
            while(x<m&&y<n)
            {
                s.push_back(mat[x][y]);
                x++;
                y++;
            }
            
            sort(s.begin(),s.end());
            
            x=0,y=i;
            int c=0;
            while(x<m&&y<n)
            {
                mat[x][y]=s[c];
                x++;
                y++;
                c++;
            }
            
        }
        
        return mat;
    }
};