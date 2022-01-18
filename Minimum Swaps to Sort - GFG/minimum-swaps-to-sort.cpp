// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    //vector<pair<int,int>> a;
	    int n=nums.size();
	    pair<int,int> a[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        //a.push_back({nums[i],i});
	        a[i].first=nums[i];
	        a[i].second=i;
	    }
	    
	    //sort(a.begin(),a.end());
	    sort(a,a+n);
	    vector<bool> v(n,false);
	    int s=0;
	    
	   // for(int i=0;i<n;i++)
	   //     cout<<a[i].first<<" ";
	   //cout<<endl;
	   //for(int i=0;i<n;i++)
	   //     cout<<a[i].second<<" ";
	    //cout<<endl;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i]||a[i].second==i)
	            continue;
	            
	        int c=0;
	        int in=i;
	        while(!v[in])
	        {
	            //cout<<in<<" "<<a[in].second<<" "<<c<<endl;
	            c++;
	            v[in]=true;
	            in=a[in].second;
	        }
	        //cout<<endl;
	        s+=c-1;
	    }
	    
	    return s;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends