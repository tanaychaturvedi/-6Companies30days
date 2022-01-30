struct myComp{
    bool operator() (string &a,string &b)
    {
        if(size(a) != size(b)) return size(a) > size(b);
        return a > b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,myComp> pq;
        
        for(auto &str : nums)
        {
            pq.push(str);
            if(size(pq) > k)
                pq.pop();
        }
        
        return pq.top();
    }
};