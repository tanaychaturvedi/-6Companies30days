class Solution {
    
    int distance(vector<int> &a,vector<int> &b)
    {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return (x*x) + (y*y); 
    }
    
    
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        if(size(points) < 3)
            return false;
        
        int cnt = 0;
        
        for(int i=0;i<size(points);i++)
        {
            unordered_map<int,int> mp;
            for(int j=0;j<size(points);j++)
            {
                int d = distance(points[i],points[j]);
                cnt += 2*(mp[d]);
                mp[d]++;
            }
        }
        
        return cnt;
    }
};