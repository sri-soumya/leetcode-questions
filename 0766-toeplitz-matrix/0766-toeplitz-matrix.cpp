class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        
        for(int k=0;k<m;k++)
        {
            int i=k+1,j=1;
            while(i<m&&j<n)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
                i++;j++;
            }
        }
        
        for(int k=0;k<n;k++)
        {
            int i=1,j=k+1;
            while(i<m&&j<n)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
                i++;j++;
            }
        }
        
        return true;
    }
};