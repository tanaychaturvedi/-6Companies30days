int atoi(string str) {
        int num = 0;
        bool isNegative = false;
        int i = 0;
        
        if(str[i] == '-')
        {
            isNegative = true;
            i++;
        }
        
        for(; i < str.size(); i++)
        {
            if(isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
            }
            else
            {
                return -1;
            }
        }
        
        return (isNegative == true) ? -num : num;
    }