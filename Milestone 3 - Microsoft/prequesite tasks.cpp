class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& preq) {
	   vector<vector<int>> g(n);
	   
	   vector<int> in(n,0);
	   
	   for(int i=0;i<size(preq);i++)
	   {
	       g[preq[i].second].push_back(preq[i].first);
	       in[preq[i].first]++;
	   }
	   
	   queue<int> q;
	   vector<int> jobs;
	   
	   for(int i=0;i<n;i++)
	   {
	       if(in[i] == 0) q.push(i);
	   }
	   
	   while(!q.empty())
	   {
	       int i = q.front(); q.pop();
	       jobs.push_back(i);
	       for(auto &child : g[i])
	       {
	           in[child]--;
	           if(in[child] == 0) q.push(child);
	       }
	   }
	   
	   return size(jobs) == n;
	}
};