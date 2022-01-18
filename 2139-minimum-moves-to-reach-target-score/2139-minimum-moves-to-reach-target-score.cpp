class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int c=0;
        while(target>1)
        {
            if(maxDoubles==0)
            {
                c+=target-1;
                target=1;
            }
            
            else if(target%2)
            {
                target--;
                c++;
            }
            else
            {
                maxDoubles--;
                target/=2;
                c++;
            }
            //c++;
        }
        
        return c;
        
    }
};