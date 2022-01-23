class Solution {
    vector<string> separate(string str)
    {
        string l = "";
        int n = str.size();
        vector<string> v;

        for(int i=0;i<n;i++)
        {
            if(str[i] == '.')
            {
                v.push_back(l);
                l="";
            }
            else l += str[i];
        }

        v.push_back(l);

        return v;
    }
public:
    int compareVersion(string A, string B) {
        vector<string> fir = separate(A), sec = separate(B);
    
        if(fir.size() > sec.size()) sec.resize(fir.size(),"0");
        else if(fir.size() < sec.size()) fir.resize(sec.size(),"0");

        for(int i=0;i<fir.size();i++)
        {
            long long val1 = stol(fir[i]), val2 = stol(sec[i]);
            // cout<<val1<<" "<<val2<<"\n";

            if(val1 > val2) return 1;
            else if(val1 < val2) return -1;
        }

        // for(auto ch : fir) cout<<ch<<" ";
        // cout<<"\n";
        // for(auto ch : sec) cout<<ch<<" ";
        // cout<<"\n";

        return 0;
    }
};