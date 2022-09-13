class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int r=0;
        
        for(auto x:data)
        {
            if(!r)
            {
                if((x>>7)==0)
                    r=0;
                else if((x>>5)==6)
                    r=1;
                else if((x>>4)==14)
                    r=2;
                else if((x>>3)==30)
                    r=3;
                else 
                    return false;
            }
            else
            {
                if((x>>6)==2)
                    r--;
                else 
                    return false;
            }
        }
        
        return r==0;
    }
};