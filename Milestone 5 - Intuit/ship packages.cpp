int shipWithinDays(vector<int>& weights, int days) {
        int start = 1 , end = 0;
        for(auto &val : weights) end += val;
        
        end++;
        
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            int d = 1, cap = mid;
            bool ok = true;
            for(auto &val : weights)
            {
                if(val > mid) 
                {
                    ok = false;
                    break;
                }
                else if(cap < val) cap = mid , d++;
                cap -= val;
            }
            
            // cout<<mid<<" "<<ok<<" "<<d<<"\n";
            
            if(!ok || d > days) start = mid+1;
            else ans = mid , end = mid - 1;
        }
        
        return ans;
    }