vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> in(n,0);
        queue<int> q;
        for(auto &edge : pre)
        {
            adj[edge[1]].push_back(edge[0]);
            in[edge[0]]++;
        }
        
        for(int i=0;i<n;i++) 
        {
            if(in[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            topo.push_back(curr);
            
            for(auto &child : adj[curr])
            {
                if(--in[child] == 0)
                    q.push(child);
            }
        }
        // vector<int> emp;
        in.clear();
        // for(auto &val : topo) cout<<val<<" ";
        
        return topo.size() != n ? in : topo;
    }