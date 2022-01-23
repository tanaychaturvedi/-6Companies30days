vector<int> subarraySum(int arr[], int n, long long s)
    {
        int start = 0 , end = 0;
        typedef long long ll;
        ll curr = 0;
        
        while(end<n)
        {
            curr += arr[end];
            
            while(start<=end and curr>s) curr -= arr[start++];
            
            if(curr == s) return {start+1,end+1};
            end++;
        }
        
        while(start<=end and curr>s) curr -= arr[start++];
        if(curr == s) return {start+1,end+1};
        
        
        return {-1};
        
    }