typedef long long ll;
    // ll mod = 1e9 + 7;
    
    ll power(ll x,ll y)
    {
        // cout<<y<<"\n";
        if(y == 0)
            return 1;
        ll temp = power(x,y/2);
        
        if(y&1)
            return (temp%mod * temp%mod * x%mod)%mod;
        else 
            return (temp%mod * temp%mod)%mod;
    }
    
    
    long long power(int N,int R)
    {
       return power(N,R);
    }