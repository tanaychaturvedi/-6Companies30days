int minDifference(int arr[], int n)  { 
	    
	    int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        int half = (sum/2);
        int dp[n+1][half + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = 1; 
        for(int i=1;i<=half;i++) dp[0][i] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=half;j++)
            {
                if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<=half;i++) 
        {
            if(dp[n][i])
            {
                ans = min(ans,abs(sum - 2*i));
            }
        }
        
        return ans;
	    
	    
	    
	}