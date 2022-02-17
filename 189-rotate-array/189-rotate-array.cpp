class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(),c=0,i=0;
        while(c<n)
        {
            int a=nums[i];
            int s=i;
            do
            {
                c++;
                int j=(s+k)%n;
                int t=nums[j];
                nums[j]=a;
                a=t;
                s=j;
            }while(s!=i);
            i++;
        }
    }
};