vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        vector<string> res;
        int mx = -1;
        
        for(auto it : mp)
        {
            string key = it.first;
            int val = it.second;
            
            if(mx < val)
            {
                mx = val;
                res = {key,to_string(val)};
            }
            else if(mx == val) res[0] = min(res[0],key);
        }
        
        return res;
    }