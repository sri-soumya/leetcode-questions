// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
    {
        if(a.first.second!=b.first.second)
            return a.first.second<b.first.second;
        
    //     if(a.first.first!=b.first.first)
    //         return a.first.first<b.first.first;
        
         return a.second<b.second;
        
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<pair<int,int>,int>> a;
        vector<int> b;
        //int n=start.size();
        
        for(int i=0;i<n;i++)
            a.push_back({{start[i],end[i]},i+1});
        
        sort(a.begin(),a.end(),compare);
        
        int s=-1;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s<a[i].first.first)
            {
                //b.push_back(a[i].second);
                c++;
                s=a[i].first.second;
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends