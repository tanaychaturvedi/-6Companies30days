int lengthOfLongestAP(int A[], int n) {
        if(n<=1) return n;
        int res = 2;
        
        vector<vector<int>> dp(n+1,vector<int>(1e4 + 5));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff = A[i] - A[j];
                dp[i][diff] = dp[j][diff] == 0 ? 2 : dp[j][diff]+1;
                res = max(res,dp[i][diff]);
            }
        }
        
        return res;
    }