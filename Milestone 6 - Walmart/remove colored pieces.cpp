class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0 , bob = 0;
        bool hasStart = false , hasEnd = false;
        
        for(int i=1;i<size(colors)-1;i++)
        {
            char ch = colors[i];
            char prev = colors[i-1];
            char next = colors[i+1];
            
            if(ch == prev and ch == next)
            {
                ch == 'A' ? alice++ : bob++;
            }
        }
        
        return alice > bob;
    }
};