class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int count_neg = 0;
        long long sum = 0;

        int max_num = INT_MIN;
        int min_num = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                max_num = max(max_num,abs(matrix[i][j]));
                min_num = min(min_num,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    count_neg++;
                }
            }
        }

        if(count_neg%2==0){
            return sum;
        }

        return sum - 2*min_num;
    }
};