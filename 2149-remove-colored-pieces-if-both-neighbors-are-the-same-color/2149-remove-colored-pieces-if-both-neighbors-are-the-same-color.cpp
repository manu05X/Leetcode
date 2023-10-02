class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        int n = colors.size();

        for(int i = 1; i < n-1; i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if(colors[i] == 'A'){
                    alice++;
                }
                else
                {
                    bob++;
                }
            }
        }
        int diff = alice - bob;
        if(diff >= 1){
            return true;
        }
        else
        {
            return false;
        }
    }
};