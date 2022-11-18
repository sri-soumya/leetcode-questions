class Solution {
public:
    bool isUgly(int m) {
        if(m<1)
            return false;
        int i=2;
        long long n=abs(m);
        
        while(n>1)
        {
            if(i>5)
                return 0;
            if(n%i==0)
            {
                n/=i;
                //cout<<i<<" "<<n<<endl;
            }
            else
                i++;
        }
        
        return i<=5;
    }
};