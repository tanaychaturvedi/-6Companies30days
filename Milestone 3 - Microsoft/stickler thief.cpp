int FindMaxSum(int arr[], int n)
    {
        int in = 0, ex = 0;
        for(int i=0;i<n;i++)
        {
            int nin = arr[i] + ex , nex = max(in,ex);
            in = nin , ex = nex;
        }
        
        return max(in,ex);
    }