class Solution {
public:
    int compareVersion(string v1, string v2) {
        v1+=".";v2+=".";
        int n=v1.length(),m=v2.length();
        string a="",b="";
        int i=0,j=0;
        
        while(i<n&&j<m)
        {
            if(v1[i]=='.'&&v2[j]=='.')
            {
                //cout<<a<<" "<<b<<endl;
                int r1=stoi(a),r2=stoi(b);
                a="";
                b="";
                i++;
                j++;
                if(r1>r2)
                    return 1;
                else if(r2>r1)
                    return -1;
            }
            
            else if(v1[i]!='.')
            {
                a+=v1[i];
                i++;
            }
            
            else
            {
                b+=v2[j];
                j++;
            }
            
            
        }
        
        while(i<n)
        {
            if(v1[i]!='.'&&v1[i]!='0')
                return 1;
            i++;
        }
        
        while(j<m)
        {
           if(v2[j]!='.'&&v2[j]!='0')
           {
               //cout<<j<<" "<<v2[j]<<endl;
               return -1;
           }
           j++; 
        }
        
        return 0;
        
    }
};