class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size();
        stack<int> a;
        map<int,int> nge;
        vector<int> ans;
        for(int i=n2-1;i>=0;i--)
        {
            while(a.size()&&a.top()<=nums2[i])
                a.pop();
            if(!a.size())
                nge[nums2[i]]=-1;
            else
                nge[nums2[i]]=a.top();
            a.push(nums2[i]);
        }
        
        //for(int i=0)
        
        for(int i=0;i<n1;i++)
            ans.push_back(nge[nums1[i]]);
        
        return ans;
        
    }
};