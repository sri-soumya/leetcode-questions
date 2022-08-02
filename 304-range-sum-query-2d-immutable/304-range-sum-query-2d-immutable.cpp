class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>> b(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n;i++)
        {
            int p=0;
            for(int j=0;j<m;j++)
            {
                p+=matrix[i][j];
                b[i+1][j+1]=p+b[i][j+1];
            }
        }
        
        a=b;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;col1++;row2++;col2++;
        
        int r=a[row2][col2];
        r=r-a[row1-1][col2]-a[row2][col1-1]+a[row1-1][col1-1];
        
        return r;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */