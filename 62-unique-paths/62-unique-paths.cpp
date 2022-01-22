class Solution {
public:
    int uniquePaths(int m, int n) {
        
        m--;n--;
        int ma=max(m,n)+1;
        int a=m+n;
        long long int p=1;
        
        for(int i=ma;i<=a;i++)
            p*=i;
        
        for(int i=2;i<=min(m,n);i++)
            p/=i;
        
        return p;
        
    }
};