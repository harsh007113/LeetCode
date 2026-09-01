class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> visit(10);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                visit[val]++;
                if(visit[val] > 1) return false;
            }
        }

         for(int j = 0; j < 9; j++){
            vector<int> visit(10);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                visit[val]++;
                if(visit[val] > 1) return false;
            }
        }

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                vector<int> visit(10);
                int u = i, d = i+2;
                int l = j, r = j+2;
                for(int p = u; p <= d; p++){
                    for(int q = l; q <= r; q++){
                        if(board[p][q] == '.') continue;
                        int val = board[p][q] - '0';
                        visit[val]++;
                        if(visit[val] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};