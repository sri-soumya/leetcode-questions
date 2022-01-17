class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
//        int m=matrix.size();
//         int n=matrix[0].size();
//         unordered_map<int,int> a,b;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     a[i]++;
//                     b[j]++;
//                 }
                
//             }
//         }
        
//         for(auto it=a.begin();it!=a.end();it++)
//         {
//             int x=it->first;
            
//             for(int i=0;i<n;i++)
//                 matrix[x][i]=0;
//         }
        
//         for(auto it=b.begin();it!=b.end();it++)
//         {
//             int x=it->first;
            
//             for(int i=0;i<m;i++)
//                 matrix[i][x]=0;
//         }
        
        int m=matrix.size();
        int n=matrix[0].size();
        int col=1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
                    col=0;
            for(int j=1;j<n;j++)
            {
                
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col==0)
                matrix[i][0]=0;
        }
        
    }
};