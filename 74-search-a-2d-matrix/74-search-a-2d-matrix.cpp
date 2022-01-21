class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool f=false;
        
        int lb=0,ub=n*m-1;
        
        while(lb<=ub)
        {
            int mi=(lb+ub)/2;
            int r=mi/n;
            int c=mi%n;
            
            if(target<matrix[r][c])
                ub=mi-1;
            else if(target>matrix[r][c])
                lb=mi+1;
            else
            {
                f=true;
                break;
            }
        }
        
        return f;
    }
};