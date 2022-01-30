class Solution {
    vector<pair<int,int>> direction = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                    q.push({i,j}) , vis[i][j] = true;
            }
        }
    
        if(q.size() == grid.size() * grid[0].size()) return -1;
        int cnt = -1;

        while(!q.empty())
        {
            int sz = q.size();
            cnt++;
            for(int i=0;i<sz;i++)
            {
                auto p = q.front(); q.pop();
                for(auto &dir : direction)
                {
                    int x = p.first + dir.first , y = p.second + dir.second;
                    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y]) continue;
                    vis[x][y] = true;
                    q.push({x,y});
                }
            }
        }

        return cnt;
    }
};