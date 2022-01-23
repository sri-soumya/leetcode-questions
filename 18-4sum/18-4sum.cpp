class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> a;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int t=target-nums[i]-nums[j];
                int f=j+1,s=n-1;
                //cout<<"here"<<endl;
                while(f<s)
                {
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[f]<<" "<<nums[s]<<endl;
                    if(nums[s]+nums[f]<t)
                        f++;
                    else if(nums[s]+nums[f]>t)
                        s--;
                    else
                    {
                        a.insert({nums[i],nums[j],nums[f],nums[s]});
                        //ans.push_back({nums[i],nums[j],nums[f],nums[s]});
                        f++;
                        s--;
                    }
                }
            }
        }
        
        
        
        for(auto i:a)
            ans.push_back(i);
        
        return ans;
    }
};