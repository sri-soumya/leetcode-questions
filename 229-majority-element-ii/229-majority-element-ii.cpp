class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        
        int n=a.size();
        int c1=0,c2=0,e1=0,e2=0;
        
        for(int i=0;i<n;i++)
        {
            
            if(a[i]==e1)
                c1++;
            else if(a[i]==e2)
                c2++;
            
           else if(c1==0)
            {
                e1=a[i];
               c1++;
            }
            else if(c2==0)
            {
                e2=a[i];
                c2++;
            }
            
            
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=0;c2=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==e1)
                c1++;
            else if(a[i]==e2)
                c2++;
        }
        
        if(c1>n/3&&c2>n/3)
            return {e1,e2};
        else if(c1>n/3)
            return {e1};
        else if(c2>n/3)
            return {e2};
        return {};
        
    }
};