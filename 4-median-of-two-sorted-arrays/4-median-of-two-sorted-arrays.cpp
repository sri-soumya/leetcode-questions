class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int tn=nums1.size()+nums2.size();
        int par=(tn+1)/2;
        int l=0,u=nums1.size();
        
        while(l<=u)
        {
            int c1=(l+u)/2;
            int c2=par-c1;
            
            int l1=(c1-1>=0)?nums1[c1-1]:INT_MIN;
            int l2=(c2-1>=0)?nums2[c2-1]:INT_MIN;
            int r1=(c1<nums1.size())?nums1[c1]:INT_MAX;
            int r2=(c2<nums2.size())?nums2[c2]:INT_MAX;
            
            if(l1>r2)
                u=c1-1;
            else if(l2>r1)
                l=c1+1;
            else
            {
                if(tn%2)
                    return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
         
        return INT_MIN;
        
    }
};