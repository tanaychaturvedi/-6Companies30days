int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;
        int end = *max_element(piles.begin(),piles.end()) + 2;
        
        int ans = h;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            int tot = 0;
            
            for(auto &val : piles)
            {
                int x = ceil((double)val/mid);
                tot += x;
            }
            
            if(tot <= h)
                ans = mid , end = mid-1;
            else 
                start = mid + 1;
            
        }
        
        
        return ans;
    }