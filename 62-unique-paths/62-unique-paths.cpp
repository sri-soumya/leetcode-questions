class Solution {
public:
    int uniquePaths(int m, int n) {
        
        m--;n--;
        
        long long int p=1;
        int x=m+n;
        
        for(int i=max(m,n)+1,j=1;i<=x&&j<=min(m,n);i++,j++)
        {
            p*=i;
            p/=j;
        }
        
        return p;
    }
};