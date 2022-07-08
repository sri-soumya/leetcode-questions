// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int countTriplets(vector<int>a){
	    // Code here.
	    int n=a.size();
	   // vector<int> l(n,0),r(n,0);
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        int s=0;
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i])
	                s++;
	               
	        }
	        
	        int p=s;
	        s=0;
	        
	        for(int j=i+1;j<n;j++)
	        {
	            if(a[j]>a[i])
	                s++;
	        }
	        
	        p*=s;
	        ans+=p;
	    }
	    
	    return ans;
	    
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends