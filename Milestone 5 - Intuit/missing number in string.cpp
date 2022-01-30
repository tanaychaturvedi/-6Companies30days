long long sto(string s)
{
    long long x=0;
    for(int i=0;i<s.size();i++)
      x=x*10+s[i]-'0';
    return x;
}

int missingNumber(const string& str)
{
    typedef long long ll;
    
    for(int len=1;len<=6;len++)
    {
        int i=0 , l = len;
        string temp = "";
        while(i<str.size() and l--)
            temp += str[i++];
        
        ll prev = sto(temp);
        temp = "";
        
        bool ok = true;
        ll cnt = 0;
        ll miss = -1;
        
        while(i<str.size())
        {
            temp += str[i++];
            
            if(prev + 1 == sto(temp))
            {
                prev = sto(temp);
                temp = "";
            }
            else if(prev + 2 == sto(temp))
            {
                miss = prev+1;
                prev = sto(temp);
                temp = "";
                cnt++;
            }
            else if(prev < sto(temp))
                ok = false;
        }
        
        if(cnt==1 and ok)
            return miss;
    }
    
    return -1;
}