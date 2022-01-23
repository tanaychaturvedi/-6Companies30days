int longestMountain(vector<int>& arr) {
        int n = size(arr);
        
        int ans = 0;
        
        for(int i=1;i<=n-2;)
        {
            if(arr[i] > arr[i-1] and arr[i]>arr[i+1])
            {
                int count = 1;
                int j=i;
                while(j>0 and arr[j]>arr[j-1])
                    count++ , j--;
                while(i<n-1 and arr[i]>arr[i+1])
                    count++ , i++;
                ans = max(ans,count);
            }
            else i++;
        }
        
        
        return  ans;
    }