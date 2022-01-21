class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0,j=n-1;
        bool f=false;
        
        while(i>=0&&i<m&&j>=0&&j<n)
        {
            if(matrix[i][j]==target)
            {
                f=true;
                break;
            }
            
            else if(target<matrix[i][j])
            {
                j--;
            }
            
            else
                i++;
        }
        
        return f;
        
    }
};