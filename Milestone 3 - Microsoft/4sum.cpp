vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        for(int i=0;i<n;)
        {
            for(int j=i+1;j<n;)
            {
                int val = k - (arr[i] + arr[j]);
                int start = j+1 , end = n-1;
                while(start < end)
                {
                    int x = arr[start] + arr[end];
                    if(x < val) start++;
                    else if(x>val) end--;
                    else
                    {
                        res.push_back({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        while(start<n and arr[start] == arr[start-1]) start++;
                        end--;
                        while(end > start and arr[end] == arr[end+1]) end--;
                    }
                }
                
                j++;
                while(j<n and arr[j] == arr[j-1]) j++;
            }
            i++;
            while(i<n and arr[i] == arr[i-1]) i++;
        }
        
        return res;
    }