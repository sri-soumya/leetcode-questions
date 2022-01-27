class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        
        int n=a.length(),m=b.length();
        
//         int in=-1;
        
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]!=b[0])
//                 continue;
//             int c=0,k=i;
//             for(int j=0;j<m;j++)
//             {
//                 if(k==n)
//                     k=0;
//                 if(a[k]==b[k])
//                 {
//                     c++;
//                     k++;
//                 }
//             }
//             if(c==m)
//             {
//                 in=i;
//                 break;
//             }
//         }
        
//         if(in==-1)
//             return -1;
//         int c=1;
//         for(int i=0;i<m;i++)
//         {
//              if(in==n)
//             {
//                 c++;
//                 in=0;
//             }
//             if(a[in]==b[i])
//                 in++;
//             else
//                 return -1;
           
//         }
        
//         return c;
        
        string c=a;
        int f=1;
        while(c.length()<b.length())
        {
            c+=a;
            f++;
        }
        //cout<<c<<endl;
        if(c.find(b)==string::npos)
        {
            if((c+a).find(b)==string::npos)
                return -1;
            return f+1;
        }
        return f;
        
    }
};