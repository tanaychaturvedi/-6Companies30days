class Solution {
    
    vector<vector<int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    
    bool recur(vector<vector<char>> &board,string word,int idx,int i,int j,vector<vector<int>> &vis)
    {
        if(idx == size(word))
            return true;
        if(word[idx] != board[i][j])
            return false;
        
        vis[i][j] = 1;
        
        for(auto d : dir)
        {
            int nx = i + d[0] , ny = j + d[1];
            if(nx>=0 and ny>=0 and nx<size(board) and ny<size(board[0]) and vis[nx][ny] == -1)
            {
                bool ok = recur(board,word,idx+1,nx,ny,vis);
                if(ok) return true;
            }
        }
        
        return false;
    }
    
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<size(board);i++)
        {
            for(int j=0;j<size(board[i]);j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> vis(size(board),vector<int> (size(board[0]),-1));
                    bool ok = recur(board,word,0,i,j,vis);
                    if(ok) return true;
                }
            }
        }
        
        return false;
    }
};