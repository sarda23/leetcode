class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int result = INT_MIN;

        for(int i=0;i<=n-2;i++){

            // 0 to i  -  0's count
            int zero_count = 0;
            for(int j=0;j<=i;j++){
                if(s[j] == '0')  zero_count++;
            }

            int one_count = 0;
            for(int j = i+1;j<n;j++){
                if(s[j] == '1')  one_count++;
            }

            result = max(result, zero_count+one_count);
        }

        return result;
    }
};