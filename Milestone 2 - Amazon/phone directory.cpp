class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
       string search = s.substr(0,1);
       set<string> st;
       vector<string> arr;
       vector<vector<string>> res;
       
       for(int i=0;i<n;i++)
       {
           if(contact[i].substr(0,1) == search) st.insert(contact[i]);
       }
       
       if(st.size() == 0)
       {
           arr.push_back("0");
           for(int i=0;i<s.size();i++) res.push_back(arr);
           return res;
       }
       
       for(auto &ele : st) arr.push_back(ele);
       res.push_back(arr);
       
       st.clear();
       
       for(int i=1;i<s.size();i++)
       {
           
           search = s.substr(0,i+1);
           
           for(auto &word : arr)
           {
               if(word.substr(0,i+1) == search)
                    st.insert(word);
           }
           
           arr.clear();
           if(st.size() == 0) {arr.push_back("0"); res.push_back(arr);}
           for(auto &ele : st) arr.push_back(ele);
           res.push_back(arr);
           st.clear();
           
       }
       
       return res;
    }
};