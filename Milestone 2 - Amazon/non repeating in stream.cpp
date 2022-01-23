string FirstNonRepeating(string A){
		   deque<char> q;
		   unordered_map<char,int> mp;
		   string res = "";
		   
		   
		   for(auto &ch : A)
		   {
		       
		       mp[ch]++;
		       if(mp[ch] == 1) q.push_back(ch);
		       while(!q.empty() and mp[q.front()]>1)
		       {
		           q.pop_front();
		       }
		       
		       if(q.empty()) res += '#';
		       else res += q.front();
		       
		   }
		   
		   
		   return res;
		}