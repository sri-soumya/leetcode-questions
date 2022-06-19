class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int s=10,c=1;
        for(int i=1;i<=n;i++)
        {
            int x=s;
            s+=(x-c)*(10-i);
            c=x;
            
        }
        return c;        
    }
};