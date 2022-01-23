vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res(n);
       stack<int> st;
       st.push(0);
       
       for(int i=1;i<=n;i++)
       {
           while(!st.empty() and price[st.top()-1]<=price[i-1]) st.pop();
           
           res[i-1] = st.empty() ? i : i-st.top();
           st.push(i);
       }
       
       
       return res;
    }