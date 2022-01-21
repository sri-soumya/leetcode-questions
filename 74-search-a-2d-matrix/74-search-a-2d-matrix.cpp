class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool f=false;
        
        for(int i=0;i<m;i++)
        {
            if(target<matrix[i][0]||target>matrix[i][n-1])
                continue;
            int v=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(v<n&&matrix[i][v]==target)
            {
                f=true;
                break;
            }
            
        }
        
        return f;
        
    }
};