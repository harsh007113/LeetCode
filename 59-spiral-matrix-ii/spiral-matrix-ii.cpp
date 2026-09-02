class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int a = 1;
        int srow = 0;
        int scol = 0;
        int erow = n - 1;
        int ecol = n - 1;
        while(srow <= erow && scol <= ecol){
            for(int j = scol; j <= ecol; j++){
                ans[srow][j] = a;
                a++;
            }
            for(int i = srow+1; i <= erow; i++){
                ans[i][ecol] = a;
                a++;
            }
            if(srow < erow){
            for(int j = ecol-1; j >= scol; j--){
                ans[erow][j] = a;
                a++;
            }
            }
            if(scol < ecol){
             for(int i = erow-1; i >= srow+1; i--){
                ans[i][scol] = a;
                a++;
            }
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
    }
};