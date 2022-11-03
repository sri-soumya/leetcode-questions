class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1,n=digits.size();
        
        for(int i=n-1;i>=0;i--)
        {
            digits[i]+=c;
            c=digits[i]/10;
            digits[i]%=10;
        }
        
        if(c)
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};