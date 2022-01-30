class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int arr[a][b];
        for(int i=0;i<a;i++) arr[i][0] = 1;
        for(int i=0;i<b;i++) arr[0][i] = 1;
        
        for(int i=1;i<a;i++)
        {
            for(int j=1;j<b;j++)
            {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        
        return arr[a-1][b-1];
    }
};