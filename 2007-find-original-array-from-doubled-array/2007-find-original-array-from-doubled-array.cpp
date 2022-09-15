class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        unordered_map<int,int> m;
        vector<int> arr,arr1;
        for(auto u:changed)
            m[u]++;
        for(auto u: changed)
        {
            if(u==0 && m[u]>1 || (u!=0 && m.find(2*u)!=m.end() && m[u]>0))
            {
                m[u]--;
                if(m[u]<=0)
                    m.erase(u);
                arr.push_back(u);
                m[2*u]--;
                if(m[2*u]<=0)
                    m.erase(2*u);
            }

        }
        return arr.size()*2==changed.size()?arr:arr1;
    }
};