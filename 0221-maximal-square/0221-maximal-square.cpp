class Solution {
public:
    // int n,m,ans=0;

    // int solve(int i,int j,vector<vector<char>> &mat,vector<vector<int>>&t){
    //     if(i>=n || j>=m || mat[i][j] == '0'){
    //         return 0;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }
    //     int right = solve(i,j+1,mat,t);
    //     int diago = solve(i+1,j+1,mat,t);
    //     int below = solve(i+1,j,mat,t);

    //     return t[i][j] = 1 + min({right,diago,below});
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        vector<vector<int>> t(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 ||j ==0){
                    t[i][j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j] == '1'){
                    t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                ans = max(ans, t[i][j]);
            }
        }

        return ans*ans;
        // n = matrix.size();
        // m = matrix[0].size();

        // vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j] == '1'){
        //             ans = max(ans, solve(i,j,matrix,t));
        //         }
        //     }
        // }
        // return ans*ans;
    }
};