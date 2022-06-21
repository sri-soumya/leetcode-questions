class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        
        int n=a.size(),i;
        priority_queue<int> pq;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>=a[i+1])
                continue;
            int x=a[i+1]-a[i];
            
            if(x<=b)
            {
                b-=x;
                pq.push(x);
            }
            
            else if(l>0)
            {
                if(pq.size()&&x<=pq.top())
                {
                    b+=pq.top();
                    pq.pop();
                    b-=x;
                    pq.push(x);
                }
                
                l--;
            }
            
            else 
                break;
            
        }
        
        return i;
        
    }
};