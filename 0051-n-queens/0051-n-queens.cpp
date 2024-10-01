class Solution {
public:

    vector<vector<string>> result;
    int N;
    
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> anti_diag;
    // bool isValid(vector<string> &board, int row, int col){
    //     // look upward
    //     for(int i = row-1;i>=0;--i){
    //         if(board[i][col] == 'Q'){
    //             return false;
    //         }
    //     }

    //     // check left diagonal upwards
    //     for(int i = row-1, j=col-1;i>=0 && j>=0;--i,--j){
    //         if(board[i][j] == 'Q'){
    //             return false;
    //         }
    //     }
    //     // check right diagonal upwards
    //     for(int i = row-1, j=col+1;i>=0 && j<N;--i,++j){
    //         if(board[i][j] == 'Q'){
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    void solve(vector<string> &board,  int row){
        if(row>=N){
            result.push_back(board);
            return;
        }

        for(int col=0;col<N;++col){
            // if(isValid(board,row,col)){
            //     board[row][col] = 'Q';

            //     solve(board,row+1);

            //     board[row][col] = '.';
            // }

            int diag_constant = row + col;
            int anti_diag_const = row - col;

            if(cols.find(col) != cols.end() || 
            diag.find(diag_constant) != diag.end() ||
            anti_diag.find(anti_diag_const) != anti_diag.end()){
                continue;
            }
            // for a given [row][col] = 'Q
            cols.insert(col);
            diag.insert(diag_constant);
            anti_diag.insert(anti_diag_const);

            board[row][col] = 'Q';
            solve(board,row+1);

            cols.erase(col);
            diag.erase(diag_constant);
            anti_diag.erase(anti_diag_const);
            board[row][col] = '.';
        }   
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n,'.')); // n=3 ->> {"...","...","..."}
        N = n;
        
        
        solve(board,0); // starting from row 0

        return result;
    }
};