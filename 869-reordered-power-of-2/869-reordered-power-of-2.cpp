class Solution {
public:
    
    bool check(int a,int b)
    {
        string x=to_string(a),y=to_string(b);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        return x==y;
    }
    
    bool reorderedPowerOf2(int n) {
        
        int x=to_string(n).length();
        string s=to_string(n);
        
        int p=1;
        while(p<=1e9)
        {
            
            if(to_string(p).length()<x)
            {
                
                p*=2;
                continue;
            }
            if(to_string(p).length()>x)
            {
                break;
            }
            
            if(check(n,p))
            {
                return true;
            }
            p*=2;
        
        }
        
        return false;
    }
};