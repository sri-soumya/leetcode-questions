class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        //map<int,int> mp;
        for(int i=num/2;i<=num;i++)
        {
            // if(mp.count(i))
            //     continue;
            string k=to_string(i);
            reverse(k.begin(),k.end());
            int z=stoi(k);
            if(i+z==num)
                return true;
            
            // mp[i]++;
            // mp[z]++;
            
        }
        
        return false;
    }
};