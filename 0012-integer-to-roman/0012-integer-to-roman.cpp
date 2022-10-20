class Solution {
public:
    string intToRoman(int num) {
        string a[4][10]={
            {"","M","MM","MMM"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","I","II","III","IV","V","VI","VII","VIII","IX"}
        };
        
        string ans="";
        ans+=a[0][num/1000];
        num%=1000;
        ans+=a[1][num/100];
        num%=100;
        ans+=a[2][num/10];
        num%=10;
        ans+=a[3][num];
        
        return ans;
    }
};