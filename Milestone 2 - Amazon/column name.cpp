string colName (long long int n)
    {
        string res = "";
        while(n)
        {
            char ch = 'A' + (n-1)%26;
            res = ch + res;
            n = (n-1)/26;
        }
        
        return res;
    }