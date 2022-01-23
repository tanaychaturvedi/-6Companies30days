int drow[4] = {1,0,-1,0};
int dcol[4] = {0,1,0,-1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size() , c = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0 , fresh = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
                fresh += grid[i][j] == 1;
            }
        }
        
        if(fresh == 0) return 0;
        
        while(!q.empty())
        {
            ++cnt;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();

                for(int x=0;x<4;x++)
                {
                    int a = node.first + drow[x] , b = node.second + dcol[x];
                    if(a<0 or b<0 or a>=r or b>=c or grid[a][b] != 1) continue;

                    grid[a][b] = 2;
                    q.push({a,b});
                    fresh--;
                }
            }
        }
        
        return fresh == 0 ? cnt-1 : -1;
        
        
    }
};