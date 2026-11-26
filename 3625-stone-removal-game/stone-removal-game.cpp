class Solution {
public:
    bool canAliceWin(int n) {
       int turn = 10;
       int steps = 0;
       while(n >= turn){
        n -= turn;
        turn--;
        steps++;
       }
       if(steps % 2 != 0){
        return true;
       } else {
        return false;
       }

    }
};