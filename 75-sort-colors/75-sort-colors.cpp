class Solution {
public:
    void sortColors(vector<int>& a) {
        
        int i=0,m=0,j=a.size()-1;
        
        while(m<=j)
        {
            if(a[m]==1)
                m++;
            else if(a[m]==0)
            {
                swap(a[i],a[m]);
                i++;
                m++;
            }
            else
            {
                swap(a[j],a[m]);
                j--;
            }
        }
        
    }
};