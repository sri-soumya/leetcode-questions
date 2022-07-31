class NumArray {
public:
    vector<int> a;
    int sum;
    NumArray(vector<int>& nums) {
        a=nums;
        sum=0;
        
        for(auto x:a)
            sum+=x;
    }
    
    void update(int index, int val) {
        sum-=a[index];
        a[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int s=sum;
        for(int i=0;i<left;i++)
            s-=a[i];
        
        for(int i=right+1;i<a.size();i++)
            s-=a[i];
        
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */