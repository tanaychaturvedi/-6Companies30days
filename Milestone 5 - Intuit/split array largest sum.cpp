class Solution {
    typedef long long ll;
    
    bool recur(vector<int> &nums,ll mid,int m)
    {
        ll sum = 0;
        for(auto &ele : nums)
        {
            if(ele > mid) return false;
            else if(ele + sum <= mid) sum += ele;
            else
            {
                --m;
                sum = ele;
                if(m < 0) return false;
            }
        }
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        
        ll start = *max_element(nums.begin(),nums.end());
        ll end = 0;
        for(auto &val : nums)
            end += val;
         
        // int ans = -1;
        
        while(start < end)
        {
            ll mid = start + (end - start)/2;
            
            bool ok = recur(nums,mid,m-1);
            
            if(ok) end = mid;
            else start = mid+1;
        }
        
        return start;
    }
};