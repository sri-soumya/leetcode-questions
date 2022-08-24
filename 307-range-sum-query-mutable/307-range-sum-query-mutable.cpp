class NumArray {
public:
    int n;
    vector<int> st;
    void build(int in,int l,int u,vector<int> &a,vector<int> &st)
    {
        if(l==u)
        {
            st[in]=a[l];
            return;
        }
        int m=(l+u)/2;
        build(in*2+1,l,m,a,st);
        build(in*2+2,m+1,u,a,st);

        st[in]=(st[in*2+1]+st[in*2+2]);
    }

    int query(int in,int l,int u,int x,int y,vector<int> &st)
    {
        if(y<l||x>u)
            return 0;
        if(l>=x&&u<=y)
            return st[in];
        int m=(l+u)/2;
        return (query(in*2+1,l,m,x,y,st)+query(in*2+2,m+1,u,x,y,st));
    }

    void update(int in,int l,int u,int ind,int x,vector<int> &st)
    {
        if(l==u&&l==ind)
        {
            st[in]=x;
            return;
        }

        int m=(l+u)/2;
        if(ind<=m)
            update(in*2+1,l,m,ind,x,st);
        else
            update(in*2+2,m+1,u,ind,x,st);
        st[in]=(st[in*2+1]+st[in*2+2]);
    }		
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(5*n);
        build(0,0,n-1,nums,st);
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val,st);
    }
    
    int sumRange(int left, int right) {
        // return 0;
        return query(0,0,n-1,left,right,st);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */