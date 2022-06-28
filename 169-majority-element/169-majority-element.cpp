class Solution {
public:
    int majorityElement(vector<int>& a) {
        
        int n=a.size();
        
        int c=0,e=0;
        
        for(int i=0;i<n;i++)
        {
            if(!c)
                e=a[i];
            if(a[i]==e)
                c++;
            else
                c--;
        }
        
        return e;
        
    }
};