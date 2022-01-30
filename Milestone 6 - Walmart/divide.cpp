int divide(int dividend, int divisor) {
        long long t=0, q=0, n=labs(dividend), m=labs(divisor);
        int sign = (dividend<0) ^ (divisor<0) ? -1 : 1;
        
        for(long long i=31;i>=0;i--)
        {
            if(t + (m<<i) <= n)
            {
                t += (m<<i);
                q += (1LL<<i);
            }
        }
        
        q = sign*q;
        
        return ((q>INT_MAX) or (q<INT_MIN)) ? INT_MAX : q;
        
    }