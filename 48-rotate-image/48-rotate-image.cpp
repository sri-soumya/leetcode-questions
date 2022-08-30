class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int t=0,l=0,b=n-1,r=n-1;
        
        while(t<=b)
        {
            for(int i=0;i<r-l;i++)
            {
                int x=matrix[t][l+i];
                matrix[t][l+i]=matrix[b-i][l];
                matrix[b-i][l]=matrix[b][r-i];
                matrix[b][r-i]=matrix[t+i][r];
                matrix[t+i][r]=x;
            }
            
            t++;
            l++;
            b--;
            r--;
        }
    }
};