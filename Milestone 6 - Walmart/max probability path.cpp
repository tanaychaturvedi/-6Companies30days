class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> arr[n];
        
        for(int i=0;i<edges.size();i++)
        {
            arr[edges[i][0]].push_back({edges[i][1],succProb[i]});
            arr[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" : ";
        //     for(auto p : arr[i]) cout<<p.first<<" "<<p.second<<" , ";
        //     cout<<"\n";
        // }
        
        vector<bool> vis(n,false);
        vector<double> pr(n,0);
        pr[start] = 1;
        multiset<pair<double,int>,greater<pair<double,int>>> st;
        st.insert({pr[start],start});
        
        while(!st.empty())
        {
            auto val = *(st.begin());
            // cout<<val.first<<" "<<val.second<<"\n";
            st.erase(st.begin());
            
            int u = val.second;
            if(vis[u]) continue;
            
            vis[u] = true;
            
            for(auto p : arr[u])
            {
                int v = p.first; double prob = p.second;
                if(!vis[v] and pr[v] < pr[u]*prob)
                {
                    pr[v] = pr[u]*prob;
                    st.insert({pr[v],v});
                }
            }
            
        }
        
        return pr[end];
        
    }
};