/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#define ll long long int
class Solution {
public:
    int guessNumber(int n) {
        
        ll l=1,u=pow(2,31)-1;
        
        while(l<=u)
        {
            ll m=(l+u)/2;
            if(guess(m)==0)
                return m;
            if(guess(m)==-1)
                u=m-1;
            else
                l=m+1;
        }
        
        return -1;
    }
};