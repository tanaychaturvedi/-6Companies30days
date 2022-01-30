class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        stack<int> st;
        
        for(int i=N-1;i>=0;i--)
        {
            while(!st.empty() and st.top() <= arr[i])
                st.pop();
            st.push(arr[i]);
            
            if(st.size() == 3)
                break;
        }
        
        vector<int> res;
        
        if(st.size() >= 3)
        {
            while(!st.empty())
            {
                res.push_back(st.top()); st.pop();
                if(res.size() == 3)
                    break;
            }
        }
        
        return res;
    }
};