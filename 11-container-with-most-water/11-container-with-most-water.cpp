class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ar=0,n=height.size();
        int i=0,j=height.size()-1;
        while(i<=j)
        {
            ar=max(ar,min(height[i],height[j])*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return ar;
        
    }
};