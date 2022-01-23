class Solution
{
    typedef long long ll;
    const ll mod = 1000000007;
    
    
    ll recur(int N,int k,int prev_cons,int idx,vector<vector<ll>> &dp)
    {
        if(idx == N) return 1;
        
        if(dp[idx][prev_cons] != -1)
            return  dp[idx][prev_cons];
        
        if(prev_cons >= k)
            return dp[idx][prev_cons] = (21%mod * recur(N,k,0,idx+1,dp)%mod)%mod;
        else
            return dp[idx][prev_cons] = (
                (5%mod * recur(N,k,prev_cons+1,idx+1,dp))%mod + 
                (21%mod * recur(N,k,0,idx+1,dp)%mod)%mod
                )%mod;
    }
    
  public:
    int kvowelwords(int N, int K) {
        vector<vector<ll>> dp(N+1,vector<ll>(K+1,-1));
        return recur(N,K,0,0,dp)%mod;
    }
};