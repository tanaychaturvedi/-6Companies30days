class Solution {
    
    vector<vector<int>> dir = {
        {1,0} , {-1,0} , {0,1} , {0,-1}
    };
    
    vector<vector<bool>> atlantic , pacific;
    vector<vector<int>> res;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = size(heights) , m = size(heights[0]);
        atlantic = pacific = vector<vector<bool>> (n,vector<bool>(m,false));
        for(int i=0;i<size(heights);i++)
        {
            dfs(heights,i,0,pacific);
            dfs(heights,i,m-1,atlantic);
        }
        
        for(int j=0;j<size(heights[0]);j++)
        {
            dfs(heights,0,j,pacific);
            dfs(heights,n-1,j,atlantic);
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>> &heights,int i,int j,vector<vector<bool>> &vis)
    {
        if(vis[i][j])
            return ;
        
        vis[i][j] = true;
        
        if(pacific[i][j] and atlantic[i][j])
        {
            res.push_back({i,j});
        }
        
        for(auto &d : dir)
        {
            int nx = i + d[0] , ny = j + d[1];
            if(nx<0 || ny<0 || nx>=size(heights) || ny>=size(heights[0]) ||
               heights[nx][ny] < heights[i][j]) 
                continue;
            dfs(heights,nx,ny,vis);
        }
        
    }
};