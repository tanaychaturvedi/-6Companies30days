class Solution
{
    void recur(int op,int cl,int n,string &str,vector<string> &res)
    {
        if(op == n and cl == n)
        {
            res.push_back(str);
            return;
        }
        
        if(op<n)
        {
            str += '(';
            recur(op+1,cl,n,str,res);
            str.pop_back();
        }
        
        if(op >= cl+1)
        {
            str += ')';
            recur(op,cl+1,n,str,res);
            str.pop_back();
        }
    }
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        string str = "";
        vector<string> res;
        
        recur(0,0,n,str,res);
        
        return res;
    }
};