class Solution {
public:
   
    bool isvalid(vector<vector<char>>& a,char k,int ci,int cj)
    {
        for(int i=0;i<9;i++)
        {
            if(a[i][cj]==k)
                return false;
            if(a[ci][i]==k)
                return false;
            if(a[3*(ci/3)+i/3][3*(cj/3)+i%3]==k)
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& a,int ci,int cj)
    {
        int i,j;
        for(i=0;i<9;i++)
        {
            //cout<<i<<" "<<j<<endl;
            for(j=0;j<9;j++)
                if(a[i][j]=='.')
                    break;
            if(j<9&&a[i][j]=='.')
                break;
        }
        if(i==9&&j==9)
            return true;
        char k;
        for(k='1';k<='9';k++)
        {
            
            if(isvalid(a,k,i,j))
            {
                //cout<<i<<" "<<j<<" "<<k<<endl;
                a[i][j]=k;
                if(solve(a,i,j))
                    return true;
                else
                    a[i][j]='.';
            }
            //a[i][j]='.';
        }
        
        //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
       solve(board,0,0);
        
    }
};