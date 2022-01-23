vector<vector<int>> dir = {
        {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}
    };
    
    bool isVal(vector<vector<int>> &grid,int i,int j)
    {
        return i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j] == 1;
    }
    
    int dfs(vector<vector<int>> &grid,int i,int j)
    {
        if(!isVal(grid,i,j)) return 0;
        grid[i][j] = 2;
        
        int cnt = 1;
        
        for(auto &d : dir)
        {
            cnt += dfs(grid,i+d[0],j+d[1]);
        }
        
        return cnt;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans = max(ans,dfs(grid,i,j));
            }
        }
        
        return ans;
    }