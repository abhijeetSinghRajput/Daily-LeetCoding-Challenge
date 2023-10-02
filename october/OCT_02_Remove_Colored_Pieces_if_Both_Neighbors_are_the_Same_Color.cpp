class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() < 3) return false;

        int alice = 0, bob = 0;
        for(int i = 1; i<colors.size()-1; i++){
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                (colors[i] == 'A')? alice++ : bob ++; 
            }
            
        }
        return alice > bob;
    }
};