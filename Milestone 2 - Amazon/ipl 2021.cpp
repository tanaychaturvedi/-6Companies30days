vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        vector<int> res;
        
        deque<int> q;
        for(int  i=0;i<k;i++) 
        {
            while(!q.empty() and q.back()<arr[i])
            {
                q.pop_back();
            }
            q.push_back(arr[i]);
        }
        
        res.push_back(q.front());
        
        int start = 0;
        
        for(int i=k;i<n;i++)
        {
            if(q.front() == arr[start++]) q.pop_front();
            while(!q.empty() and q.back()<arr[i]) q.pop_back();
            q.push_back(arr[i]);
            res.push_back(q.front());
        }
        return res;
        
    }