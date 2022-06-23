class Solution {
public:
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& a) {
        
        int n=a.size();
        sort(a.begin(),a.end(),compare);
        priority_queue<int> q;
        int s=0;
        
        for(int i=0;i<n;i++)
        {
            s+=a[i][0];
            q.push(a[i][0]);
            
            if(s>a[i][1])
            {
                s-=q.top();
                q.pop();
            }
        }
        
        return q.size();
            
    }
};