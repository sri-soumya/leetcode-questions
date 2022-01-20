class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=0;i<n;i++)
            nums1[m+i]=nums2[i];
        m+=n;
        for(int g=ceil(m/2.0);g>=1;g=ceil(g/2.0))
        {
            
            for(int i=0;i<m-g;i++)
            {
                if(nums1[i]>nums1[i+g])
                {
                    
                    swap(nums1[i],nums1[i+g]);
                }
            }
            
            if(g==1)
                break;
        }
        
        
        
    }
};