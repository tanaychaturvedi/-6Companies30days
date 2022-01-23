vector<int> leaders(int a[], int n){
        vector<int> res;
        
        int mx = a[n-1];
        res.push_back(a[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] >= mx) res.push_back(a[i]);
            mx = max(a[i],mx);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }