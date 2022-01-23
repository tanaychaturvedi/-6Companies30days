class Solution{
    
    void dfs(vector<int> g[],int node,stack<int> &st,bool vis[])
    {
        vis[node] = true;
        for(auto &child : g[node])
        {
            if(!vis[child])
            {
                dfs(g,child,st,vis);
            }
        }
        
        st.push(node);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> g[K];
        
        for(int i=0;i<N-1;i++)
        {
            int mn = min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<mn;j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    int u = dict[i][j]-'a' , v = dict[i+1][j]-'a';
                    g[u].push_back(v);
                    break;
                }
            }
        }
        
        stack<int> st;
        bool vis[K];
        string res;
        memset(vis,false,sizeof vis);
        for(int i=0;i<K;i++)
        {
            if(vis[i]) continue;
            dfs(g,i,st,vis);
        }
        while(!st.empty())
        {
            res += 'a' + st.top();
            st.pop();
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};