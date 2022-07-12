class Solution {
public:
   
    bool solve(vector<int> &a,int i,vector<int> &b,int s)
    {
        
        if(i<0)
        {
            return (b[0]==b[1]&&b[0]==b[2]&&b[0]==b[3])&&b[0]!=0;
        }
        bool c=false;
        for(int j=0;j<4;j++)
        {
            if(b[j]+a[i]>s)
                continue;
            
            int k=j-1;
            while(k>=0)
            {
                if(b[j]==b[k])
                    break;
                k--;
            }
            
            if(k>=0)
                continue;
            
            b[j]+=a[i];
            c=c||solve(a,i-1,b,s);
            if(c)
                return c;
            b[j]-=a[i];
        }
        return c;
    }
    
    bool makesquare(vector<int>& a) {
        int n=a.size(),s=0;
        
        for(auto x:a)
            s+=x;
        sort(a.begin(),a.end(),greater<int>());
        if(s%4||s/4<a[0])
            return false;
        vector<int> b(4,0);
        
        return solve(a,n-1,b,s/4);
        
    }
};