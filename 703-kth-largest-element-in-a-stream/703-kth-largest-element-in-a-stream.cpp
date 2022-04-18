class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> q;
    int k;
    KthLargest(int o, vector<int>& nums) {
        k=o;
        for(int i=0;i<nums.size();i++)
        {
            if(q.size()<k)
                q.push(nums[i]);
            else if(q.top()<nums[i])
            {
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(q.size()<k)
            q.push(val);
        else if(val>q.top())
        {
            q.pop();
            q.push(val);
        }
        
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */