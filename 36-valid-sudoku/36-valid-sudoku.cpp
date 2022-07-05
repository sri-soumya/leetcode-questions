class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a){
        
        vector<vector<bool>> b(9,vector<bool>(9,0)),c(9,vector<bool>(9,0)),d(9,vector<bool>(9,0));
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[i][j]=='.')
                    continue;
                int x=(a[i][j]-'0')-1,k=i/3*3+j/3;
                if(b[i][x]||c[j][x]||d[k][x])
                    return false;
                b[i][x]=1;
                c[j][x]=1;
                d[k][x]=1;
            }
        }
        
        return true;
        
    }
};