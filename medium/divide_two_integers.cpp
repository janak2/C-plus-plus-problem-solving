/**
 * Q.Divide two integers without using multiplication, division and mod operator. If it is overflow, return MAX_INT.
 *
 * -(N_INT_MAX) = (P_INT_MAX +1) = N_INT_MAX
 *
 */
 
class Solution {
public:
    int divide(int dividend, int divisor) {
        long c = 1,q=0, t= dividend, d= divisor;
        t= abs(t); d=abs(d);
        while(t>=d)
        {
            d<<=1;
            c<<=1;
        }
        d>>=1;
        c>>=1;
        while(c>0)
        {
            if(t>=d)
            {
                t-=d;
                q+=c;
            }
            d>>=1;
            c>>=1;
        }
        if(dividend<0 && divisor>0)return -q;
        else if(dividend>0 && divisor<0)return -q;
        if(q>2147483647)return 2147483647;
        return q;
    }
};

