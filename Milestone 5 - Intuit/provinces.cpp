class Solution {
    
    int findPar(int x,int par[])
    {
        if(par[x] == x) return x;
        
        return par[x] = findPar(par[x],par);
    }
    
    void unon(int u,int v,int par[])
    {
        u = findPar(u,par) , v = findPar(v,par);
        if(u != v) par[u] = v;
    }
    
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int par[size(isConnected)];
        int n = size(isConnected);
        for(int i=0;i<n;i++) par[i] = i;
        
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1) unon(i,j,par);
            }
            // if(isC)
        }
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[findPar(i,par)]++;
        
        return size(mp);
        
    }
};