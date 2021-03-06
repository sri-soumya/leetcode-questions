class Solution {
public:
    int strStr(string h, string a) {
        
        if(a.length()==0)
            return 0;
        
        int n=h.length(),m=a.length();
        vector<int> pi(m);
        pi[0]=0;
        
        int i=1,j=0;
        while(i<m)
        {
            if(a[i]==a[j])
            {
                j++;
                pi[i]=j;
                i++;
            }
            else
            {
                if(j==0)
                {
                    pi[i]=0;
                    i++;
                }
                
                else
                    j=pi[j-1];
            }
        }
        
        
        
        j=-1,i=0;
        
        while(i<n)
        {
            if(h[i]==a[j+1])
            {
                i++;
                j++;
            }
            
            else
            {
                if(j==-1)
                    i++;
                else
                    j=pi[j]-1;
                    
            }
            
            if(j==m-1)
                return i-m;
        }
        
        return -1;
    }
};