class Solution {
public:
    int n; // rows
    int m; // cols

    vector<int> directions = {-1,0,1};
    int DFS(int row, int col, vector<vector<int>>& grid,vector<vector<int>> &t){
        
        if(t[row][col] != -1){
            return t[row][col];
        }
        int moves = 0;
        for(int &dir:directions){
            int new_row = row + dir;
            int new_col = col + 1;

            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && grid[new_row][new_col] > grid[row][col]){
                moves = max(moves, 1+DFS(new_row,new_col,grid,t));
            }
        }
        return t[row][col] = moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> t(n,vector<int>(m,-1));

        int result = 0;
        for(int row = 0;row<n;row++){
            result  = max(result, DFS(row,0,grid,t));
        }    
        return result;
    }
};