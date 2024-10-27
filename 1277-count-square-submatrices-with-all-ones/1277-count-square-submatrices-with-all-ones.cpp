class Solution {
public:
    //int m,n;

    // int solve(int i,int j,vector<vector<int>> &mat,vector<vector<int>>& t){
    //     if(i>=m || j>=n){ // out of bound i<0 wala condition aayega hi nahi q ki i j increase hi kar rahe hai
    //         return 0;
    //     }

    //     if(mat[i][j] == 0){
    //         return 0;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }
    //     int right = solve(i,j+1,mat,t);
    //     int dia   = solve(i+1,j+1,mat,t);
    //     int below = solve(i+1,j,mat,t);

    //     return t[i][j] = 1 + min({right,dia,below});
    // }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;

        vector<vector<int>> t(m, vector<int>(n,0));

        // t[i][j] - total square submatrices having 1's ending at cell [i][j]

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // base case 
                if(i==0 || j==0){
                    t[i][j] = matrix[i][j] == 0 ? 0 : 1;
                }
                else if(matrix[i][j] == 1){
                        t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                result += t[i][j];
            }

            
        }
        return result;


        // m = matrix.size();
        // n = matrix[0].size();

        // int result = 0; // total number of square submatrixes having only 1's
        
        // vector<vector<int>> t(m+1, vector<int>(n+1,-1));
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j] == 1){
        //             result += solve(i,j,matrix,t);
        //         }
        //     }
        // }

        // return result;
    }
};