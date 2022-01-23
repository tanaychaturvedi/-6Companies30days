string f(int i)
{
    string bin = "";
    while(i)
    {
        bin += '0' + (i%2);
        i /= 2;
    }
    
    reverse(bin.begin(),bin.end());
    return bin;
}

vector<string> generate(int N)
{
	vector<string> res;
	for(int i=1;i<=N;i++)
	{
	    res.push_back(f(i));
	}
	
	return res;
}