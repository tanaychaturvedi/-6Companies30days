void dfs(vector<int> g[],int par,int node,set<vector<int>> &st,int disc[],int low[],int timer)
    {
        disc[node] = low[node] = timer++;
        
        for(auto &child : g[node])
        {
            if(disc[child] == -1)
            {
                dfs(g,node,child,st,disc,low,timer);
                low[node] = min(low[node],low[child]);
                if(low[child] > disc[node])
                    st.insert({node,child});
            }
            else if(child != par) low[node] = min(low[node],disc[child]);
        }
        
        
    }

    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int timer = 0;
        int disc[V] , low[V];
        memset(disc,-1,sizeof disc);
        memset(low,-1,sizeof low);
        
        set<vector<int>> st;
        
        for(int i=0;i<V;i++)
        {
            if(disc[i] == -1)
                dfs(adj,-1,i,st,disc,low,timer);
        }
        
        return st.find({c,d}) != st.end() || st.find({d,c}) != st.end();
    }