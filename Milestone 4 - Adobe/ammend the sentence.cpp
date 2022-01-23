string amendSentence (string s)
    {
        string res = "";
        string str = "";
        
        for(auto &ch : s)
        {
            if(ch>='a' and ch<='z') str += ch;
            else
            {
                if(size(str) > 0)
                {
                    if(size(res) > 0) res += " " + str;
                    else res += str;
                }
                
                int gap = ch - 'A';
                char x = 'a' + gap;
                str = "";
                str += x;
            }
        }
        
        if(size(str) > 0)
        {
            if(size(res) > 0) res += " " + str;
            else res += str;
        }
        
        return res;
    }